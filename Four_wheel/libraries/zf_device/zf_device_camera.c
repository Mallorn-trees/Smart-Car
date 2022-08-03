/*********************************************************************************************************************
* COPYRIGHT NOTICE
* Copyright (c) 2019,��ɿƼ�
* All rights reserved.
*
* �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
* ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
*
* @file             zf_device_camera
* @company          �ɶ���ɿƼ����޹�˾
* @author           ��ɿƼ�(QQ790875685)
* @version          �鿴doc��version�ļ� �汾˵��
* @Software         MounRiver Studio V1.51
* @Target core      CH32V307VCT6
* @Taobao           https://seekfree.taobao.com/
* @date             2021-11-25
* @note             version:
*                   V1.1 2021.12.02 ���Ӵ��ڷ���ͼ����λ������
********************************************************************************************************************/

#include "zf_device_mt9v03x_dvp.h"
#include "zf_device_scc8660_dvp.h"
#include "zf_device_camera.h"
#include "zf_device_type.h"

uint8 camera_send_image_frame_header[4] = {0x00, 0xFF, 0x01, 0x01};

//-------------------------------------------------------------------------------------------------------------------
// @brief       ����ͷ���ڻص�����
// @param       void
// @return      void
// Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void camera_uart_handler (void)
{
    if(camera_type == CAMERA_BIN_UART)
    {
        // С����ݲ�֧��
        //ov7725_cof_uart_interrupt();
    }
    else if(camera_type == CAMERA_GRAYSCALE)
    {
        // ����紮�ڻص�����
        mt9v03x_uart_callback_dvp();
    }
    else if(camera_type == CAMERA_COLOR)
    {
        //��ͫ���ڻص�����
        scc8660_uart_callback_dvp();
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       ����ͷ���жϻص�����
// @param       void
// @return      void
// Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void camera_vsync_handler (void)
{
    //����Ҫ
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       ����ͷ�ɼ����DMA�ص�����
// @param       void
// @return      void
// Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void camera_dma_handler (void)
{
    //����Ҫ
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       ����ͷDVP�ӿڻص�����
// @param       void
// @return      void
// Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void camera_dvp_handler(void)
{
    if(camera_type == CAMERA_COLOR)
    {
        scc8660_vsync_dvp();
    }
    else if(camera_type == CAMERA_GRAYSCALE)
    {
        mt9v03x_handler_dvp();
    }
    else if(camera_type == CAMERA_BIN_UART)
    {
        //С��粻֧��
    }
}


//-------------------------------------------------------------------------------------------------------------------
// @brief       ����ͷ������ͼ�����ݽ�ѹΪʮ�����ư�λ���� С�����
// @param       *data1          ����ͷͼ������
// @param       *data2          ��Ž�ѹ���ݵĵ�ַ
// @param       image_size      ͼ��Ĵ�С
// @return      void
// Sample usage:                camera_binary_image_decompression(&ov7725_image_binary[0][0], &data_buffer[0][0], OV7725_SIZE);
//-------------------------------------------------------------------------------------------------------------------
void camera_binary_image_decompression (uint8 *data1, uint8 *data2, uint32 image_size)
{
    uint8  i = 8;

    while(image_size--)
    {
        i = 8;
        while(i--)
        {
            *data2++ = ((*data1 >> i)&0x01 ? 255:0);
        }
        data1++;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       ����ͷͼ��������λ���鿴ͼ��
// @param       uartn           ʹ�õĴ��ں�
// @param       *image_addr     ��Ҫ���͵�ͼ���ַ
// @param       image_size      ͼ��Ĵ�С
// @return      void
// Sample usage:                camera_send_image(DEBUG_UART_INDEX, &mt9v03x_image[0][0], MT9V03X_IMAGE_SIZE);
//-------------------------------------------------------------------------------------------------------------------
void camera_send_image (uart_index_enum uartn, void *image_addr, uint32 image_size)
{
    // ��������
    uart_write_byte(uartn,0x00);
    uart_write_byte(uartn,0xff);
    uart_write_byte(uartn,0x01);
    uart_write_byte(uartn,0x01);

    // ����ͼ��
    uart_write_buffer(uartn, (uint8*)image_addr, image_size);
}

/***********************************************************add***************************************************************/
uint8_t Ostu_Threshold=60;//74//61
uint8_t L_black[70];
uint8_t R_black[70];
uint8_t LCenter[70];
#define byte uint8_t
#define black_block 0
#define white_block 1
uint8_t image201[1628];
uint8_t BinPixels[70][186];
float t;
float variance;
float maxVariance = 0, w0 = 0, avgValue = 0;
float u = 0;// ����ͼ��ƽ���Ҷ�
float histogram[256];

//���
void Ostu(void)
{
    //��ʼ��
    u = 0;
    avgValue = 0;
    w0 = 0;
    maxVariance = 0;
    //��ջҶ�����
    for(int i = 0; i < 256; i++)
    {
            histogram[i] = 0;
    }

    // ���ɻҶ���״ͼ
    uint8_t *p_image = &mt9v03x_image_dvp[15][1];
    for (uint8_t i = 0; i < 70; i+=2)
    {
            for (int j = 0; j < 186; j+=3)
            {//44-374
                    ++histogram[*p_image];
                    p_image+=3;
            }
            p_image += 186;
    }


    for (int16_t i = 0; i < 256; ++i)
    {
            if(histogram[i] == 0)
            {
                continue;
            }
            histogram[i] = histogram[i] / (35 * 62);
            u += i * histogram[i];
    }

    for (int16_t i = 0; i < 100; ++i)
    {
            w0 += histogram[i];  //ǰ���Ҷ�
            avgValue += i * histogram[i];
            t = avgValue / w0 - u;
            variance = t * t * w0 / (1 - w0); // g = w0/(1-w0)*(u0-u1)^2
            if (variance > maxVariance)
            { //�ҵ�ʹ�ҶȲ�����ֵ
                    maxVariance = variance;
                    Ostu_Threshold = i;            //�Ǹ�ֵ������ֵ
            }
    }
    //����ֵ�޷�
    if (Ostu_Threshold > 200)
    {
            Ostu_Threshold = 200;
    }
    if (Ostu_Threshold < 120)
    {
            Ostu_Threshold = 120;
    }
}

//��ֵ������
uint8 Look_start=15;
void compress_image()
{
    uint8_t Bin_Array[256];
    uint8_t i;
    uint8_t *p_image = &mt9v03x_image_dvp[Look_start][0];
    uint8 *p_Pixels = &BinPixels[0][0];
    uint8_t H,W;
    Ostu();
    for(i = 0; i < Ostu_Threshold; i++)
        Bin_Array[i] = 0;
    for(i = Ostu_Threshold; i < 255; i++)
        Bin_Array[i] = 1;
    for(H = 0;H<70;H++)
    {
        for(W = 0;W<186;W++)
        {
            *p_Pixels = Bin_Array[*p_image];
            p_image++;
            p_Pixels++;
        }
    }
}

const uint8_t OledDian[128]=
{
    0,1,2,4,5,7,8,10,11,13,
    14,16,17,19,20,22,23,24,26,27,
    29,30,32,33,35,36,38,39,41,42,
    44,45,47,48,49,51,52,54,55,57,
    58,60,61,63,64,66,67,69,70,71,
    73,74,76,77,79,80,82,83,85,86,
    88,89,91,92,94,95,96,98,99,101,
    102,104,105,107,108,110,111,113,114,116,
    117,118,120,121,123,124,126,127,129,130,
    132,133,135,136,138,139,141,142,143,145,
    146,148,149,151,152,154,155,157,158,160,
    161,163,164,165,167,168,170,171,173,174,
    176,177,179,180,182,183,184,185,
};



void display_oled()
{
    uint8_t data,i,j,k;
    for(j=0; j<8; j++)
    {
        oled_set_coordinate(0,j);
        for(i=0; i<128; i++)
        {
            data=0;
            for(k=0; k<8; k++)
            {
                data+=(BinPixels[63-(j*8+k)][OledDian[126-i]])<<k;              //����ֱ�İ˸����غϳ�һ���ֽ�x
            }
            oled_write_data(data);
        }
    }
}




