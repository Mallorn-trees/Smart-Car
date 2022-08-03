/*
 * picture_process.c
 *
 *  Created on: Aug 2, 2022
 *      Author: hp
 */

#include "picture_process.h"


uint8_t zhongold=93,leftold,rightold;
uint8_t leftflag[70],rightflag[70];

signed short int duanhang0,duanhang1;
uint16_t duanhangju,break_hangshu;

int leftline[120];  //������߽�
int rightline[120];  //�����ұ߽�
int centerline[120]; //�����м���

int road_width[120];//��·���   �����80����ֻɨ����80��
void image_scan()                  //1��        0��
{
    int line=0;     //��
    int list=0;     //��
    for(line=0;line<65;line++)
    {
        for(list=92;list<186;list++)
        {
            if((BinPixels[line][list-2]==1)&&(BinPixels[line][list-1]==0) &&(BinPixels[line][list]==0))
            {
                leftline[line]=list-3;
                break;
            }
        }

        for(list=92;list>1;list--)
        {
            if((BinPixels[line][list]==0)&&(BinPixels[line][list+1]==0)&&(BinPixels[line][list+2]==1))
            {
                rightline[line]=list+3;
                break;
            }
        }
        road_width[line]=myabs((leftline[line]-rightline[line]));
        centerline[line]=(rightline[line]+leftline[line])/2;
    }
    for(line=0;line<65;line++)
    {
        BinPixels[line][leftline[line]]=0;
        BinPixels[line][rightline[line]]=0;
        BinPixels[line][centerline[line]]=0;
    }
}
void zhongxian()
{

    int hang;
    int lie;
    int guixian = 0;
    int zhongold2 = 0;
    //��һ��ɨ�ߣ���ȡ0-50�������ߵ�ֵ
    for (hang = 0; hang < 50; hang++)
    {
        for (lie = zhongold; lie >= 1; lie--)
        {
            if (lie >= (int)185) lie = 184;
            if (BinPixels[hang][ lie - 1] == 0 && BinPixels[hang][ lie] == 0 && BinPixels[hang][lie + 1] == 1) //�ڰ�
            {

                R_black[hang] = (unsigned char)(lie + 1);
                rightold = (int)(lie + 1);
                rightflag[hang] = 1;
                break;
            }
            else
            {

                R_black[hang] = 0;
                rightflag[hang] = 0;
            }
        }
        for (lie = zhongold; lie < 185; lie++)
        {
            if (lie == 0) lie = 1;
            if (BinPixels[hang][ lie + 1] == 0 && BinPixels[hang][ lie] == 0 && BinPixels[hang][ lie - 1] == 1)
            {

                L_black[hang] = (unsigned char)(lie - 1);
                leftold = (int)(lie - 1);
                leftflag[hang] = 1;
                break;
            }
            else
            {

                L_black[hang] = 186;
                leftflag[hang] = 0;
            }
        }
        //��һ�е�ɨ������һ�еĻ�����������ɨ
        zhongold = (int)((L_black[hang] + R_black[hang]) / 2);
    }
    for (hang = 0; hang < 50; hang++)
    { LCenter[hang] = (unsigned char)((L_black[hang] + R_black[hang]) / 2); }

    /*����ɨ��*/
    duanhang0 = 0;
    duanhang1 = 0;
    for (hang = 1; hang < 50; hang++)  //ɨ�ϵ�0
    {
    /*
    ����0��ԭ��:��������ͷ�ӽǣ����ֳ�������Ӧ���ǽ���ԶС�ģ����Զ
    ������ ��ȱȽ����Ĵ���ô��Ϊ���ֵ�һ�����С�(��ҿ�����һ��ʮ
    ��·�ڵ��·� ������ȱ��)
    */
        if ((L_black[hang] - R_black[hang]) <= (L_black[hang - 1] - R_black[hang - 1])) { };
        if ((L_black[hang] - R_black[hang]) - (L_black[hang - 1] - R_black[hang - 1]) >= 4&&hang>=13)
        {
            duanhang0 = hang - 1;
            duanhangju = (L_black[hang - 1] - R_black[hang - 1]);

            break;
        }
    }

    if (duanhang0 > 10)
    {
    /*
    ���ɨ�赽����0����ô�Ӷ���0��ʼ��ͼ����������⣬
    ��������ѡ��̶���ֹ����ɨ�ߣ�Ѱ�Ҷ���1�Ĵ��ڡ�
    (����1��ԭ��������ٴα�С��С�ڶ���0���Ŀ�ȣ�
    ��Ϊ����ȷ�Ķ���1����ҿ�����һ��ʮ��·�ڵ��ϰ��)


   */
        advanced_regression(0, duanhang0 - 9, duanhang0 - 7, duanhang0 - 5, duanhang0 - 3); //��ʾ���д�б��
        zhongold2 = LCenter[duanhang0 - 7];
        for (hang = (int)(duanhang0 + 3); hang < 50; hang++)  //�̶���ֵɨ��
        {
            for (lie = (int)zhongold2; lie >= 1; lie--)  //ɨ����
            {
                if (lie >= 185) lie = 184;
                if (BinPixels[hang][ lie - 1] == 0 && BinPixels[hang][ lie] == 0 && BinPixels[hang][ lie + 1] == 1) //�׺ں�
                {

                    R_black[hang] = (unsigned char)(lie + 1);
                    rightold = (int)(lie + 1);
                    rightflag[hang] = 1;
                    break;
                }
                else
                {

                    R_black[hang] = 0;
                    rightflag[hang] = 0;
                }
            }
            for (lie = (int)zhongold2; lie < 185; lie++)  //ɨ����
            {
                if (lie == 0) lie = 1;
                if (BinPixels[hang][ lie + 1] == 0 && BinPixels[hang][ lie] == 0 && BinPixels[hang][ lie - 1] == 1)
                {

                    L_black[hang] = (unsigned char)(lie - 1);
                    leftold = (int)(lie - 1);
                    leftflag[hang] = 1;
                    break;
                }
                else
                {

                    L_black[hang] = 186;
                    leftflag[hang] = 0;
                }
            }
        }
    }
    for (hang = (int)(duanhang0 + 3); hang < 50; hang++)//ɨ�ϵ�1
    {
     /*
    �����Ƿ���ڶ���1
    */
        if ((L_black[hang] - R_black[hang]) < duanhangju-15&&L_black[hang]<=180&&R_black[hang]>=5)
        {
            duanhang1 = (signed short int)hang;
          //  SetText("    �ҵ�����1    " + duanhang1);
          //   SetText("    duanhangju1    " + calkuan[duanhang1]);
            break;
        }
    }
    if (duanhang0 > 10 && duanhang1 != 0)
    {
      /*
    �ҵ�����1����ʼ�������ɨ��ģʽ
    ����ɨ��˼·:�Ӷ���1����ʼʹ�ö���0����ֵ����ɨ�ߣ���̬�̳���ֵ����ɨ��
     */
        zhongold2 = LCenter[duanhang0 - 7];

        int gudingtime = 1;
        for (hang = (int)(duanhang1); hang < 50; hang++)  //����ɨ��
        {
            for (lie = (int)zhongold2; lie >= 1; lie--)  //ɨ����
            {
                if (lie >= 185) lie = 184;
                if (BinPixels[hang][ lie - 1] == 0 && BinPixels[hang][ lie] == 0 && BinPixels[hang][lie + 1] == 1) //�׺ں�
                {

                    R_black[hang] = (unsigned char)(lie + 1);
                    rightold = (int)(lie + 1);
                    rightflag[hang] = 1;
                    break;
                }
                else
                {

                    R_black[hang] = 0;
                    rightflag[hang] = 0;
                }
            }
            for (lie = (int)zhongold2; lie < 185; lie++)  //ɨ����
            {
                if (lie == 0) lie = 1;
                if (BinPixels[hang][ lie + 1] == 0 && BinPixels[hang][ lie] == 0 && BinPixels[hang][lie - 1] == 1)
                {

                    L_black[hang] = (unsigned char)(lie - 1);
                    leftold = (int)(lie - 1);
                    leftflag[hang] = 1;
                    break;
                }
                else
                {

                    L_black[hang] = 186;
                    leftflag[hang] = 0;
                }
            }
            if (gudingtime != 0) gudingtime = gudingtime + 1;
            if (gudingtime == 8) gudingtime = 0;
            if (gudingtime != 0) zhongold2 = LCenter[duanhang0 - 7];
            if (gudingtime == 0) zhongold2 = (L_black[hang] + R_black[hang]) / 2;

        }
    }

    //  ��ֹ
    //������ʾ������
    for (hang = 0; hang < 69; hang++)  //ȥ���ӵ�
    {
        LCenter[hang] = (unsigned char)((L_black[hang] + R_black[hang]) / 2);
        if (hang > 5)
        {
            if (BinPixels[hang][ LCenter[hang]] == 0 && BinPixels[hang + 1][LCenter[hang]] == 0/*&&huandao_memory!=4&&huandao_memoryforleft!=4*/)
            {

                for (guixian = hang; guixian < 70; guixian++)
                {
                    LCenter[hang] = LCenter[hang - 1];
                    L_black[guixian] = 0;
                    R_black[guixian] = 0;
                }
                break;
            }
        }
    }

    int j;

    break_hangshu = 0;
    for (j = 0; j < 50; j++)
    {
        if ((BinPixels[j][ LCenter[j]]) == 0 && (BinPixels[j + 1][ LCenter[j]]) == 0/*&& huandao_memory != 4 && huandao_memoryforleft != 4*/)
        {
            break_hangshu =  (int16)j;
            //last_break_hangshu = break_hangshu;
            //Ҳ����˵��ʮ��һ���ǲ���break��
            if (break_hangshu >= 20)    //��ֹ��һ��ʼ��break
            {
                break;
            }
        }
        if ((BinPixels[j][ LCenter[j]]) == 0 && (BinPixels[j + 1][ LCenter[j+1]]) == 0 && (BinPixels[j + 2][ LCenter[j+2]]) == 0 && (BinPixels[j + 3][ LCenter[j+3]]) == 0 /* && (huandao_memory == 4 || huandao_memoryforleft == 4)*/)
        {
            break_hangshu = (int16)j;
            //last_break_hangshu = break_hangshu;
            //Ҳ����˵��ʮ��һ���ǲ���break��
            if (break_hangshu >= 20)    //��ֹ��һ��ʼ��break
            {
                break;
            }
        }
    }
    if (break_hangshu == 0) break_hangshu = 50;
    zhongold = LCenter[4];
    if (break_hangshu >= 4)
    {
        int calendleft =0;
        int calendright = 0;
        int i;
        for (i = break_hangshu - 1; i >= 4; i--)
        {
            if (My_Abs(L_black[i], L_black[i - 1]) <= 4&&L_black[i]!=186)
            {
            //��������ߵ�������Ч����
                calendleft = i-1;
             //   SetText("calendleft " + calendleft);
                break;
            }
        }
        for (i = calendleft; i >= 4; i--)
        {
            if (L_black[i] == L_black[i - 1]) calendleft = i - 1;
            if (L_black[i] != L_black[i - 1]) break;
        }
        for (i = break_hangshu - 1; i >= 4; i--)
        {
            if (My_Abs(R_black[i], R_black[i - 1]) <= 4&&R_black[i]!=0)
            {
            //�����ұ��ߵ�������Ч����
                calendright = i-1;
              //  SetText("calendright " + calendright);
                break;
            }
        }
        for (i = calendright; i >= 4; i--)
        {
            if (R_black[i] == R_black[i - 1]) calendright = i - 1;
            if (R_black[i] != R_black[i - 1]) break;
        }
    //    SetText("break_hangshu " + break_hangshu);
     //   SetText("calendleft " + calendleft);
     //   SetText("calendright " + calendright);
        if (calendleft >= 45) calendleft = 45;
        if (calendright >= 45) calendright = 45;
        //��ʼ��
        //int calbeginleft=0;
        //int calbeginright=0;
        //for (i = 0; i <= 12; i++)
        //{
        //    if (R_black[i] != 0)
        //    {
        //        calbeginright = i;
        //        break;
        //    }
        //}
        //for (i = 0; i <= 12; i++)
        //{
        //    if (L_black[i] != 186)
        //    {
        //        calbeginleft = i;
        //        break;
        //    }
        //}
        //SetText("calbeginleft " + calbeginleft);
      //  SetText("calbeginright " + calbeginright);
       // SetText(" L_black[calbeginleft]  " + L_black[calbeginleft]);
       // SetText("L_black[calendleft]  " + L_black[calendleft]);
        //SetText(" R_black[calbeginright]  " + R_black[calbeginright]);
        //SetText(" R_black[calendright]  " + R_black[calendright]);
        /*
//      ����Ĵ������������㻷������ز��������и����жϡ�
//       */
//        if (calendleft >= 20)
//        {
//
//            pianfangcal(0, calendleft, 1);
//        }
//        if (calendleft < 20)
//        {
//          pianfangcal(0, break_hangshu - 3, 1);
//        }
//        if (calendright >= 20)
//        {
//            pianfangcal(0, calendright, 2);
//        }
//        if (calendright < 20)
//        {
//            pianfangcal(0, break_hangshu - 3, 2);
//        }
    }
//    countprotect = 0;
//    if (turepodaoflag == 0 && rukuflag == 0)  //�µ����˳�  ���ɲ��10֡�������˳�
//    {
//        for (j = 0; j <= 185; j++)  //�˳�
//        {
//            if ((BinPixels[0][ j]) == 0)
//            {
//                countprotect = countprotect + 1;
//            }
//            if (countprotect == 186) { protect = 1; break; }
//        }
//    }
//    rightopen = R_black[0];
//    leftend = L_black[0];

}

    //LWL�Ĺ����м�ɨ��
//int leftline[120];  //������߽�
//int rightline[120];  //�����ұ߽�
//int centerline[120]; //�����м���
//int road_width[120];//��·���   �����80����ֻɨ����80��
//float image_scan()                  //1��        0��
//{
//    float zxzhi=0;
//    int line=0;     //��
//    int list=0;     //��
//    for(line=0;line<69;line++)
//    {
//        for(list=92;list<186;list++)
//        {
//            if((BinPixels[line][list-2]==1)&&(BinPixels[line][list-1]==0) &&(BinPixels[line][list]==0))
//            {
//                leftline[line]=list-3;
//                break;
//            }
//        }
//
//        for(list=92;list>1;list--)
//        {
//            if((BinPixels[line][list]==0)&&(BinPixels[line][list+1]==0)&&(BinPixels[line][list+2]==1))
//            {
//                rightline[line]=list+3;
//                break;
//            }
//        }
//        road_width[line]=myabs((leftline[line]-rightline[line]));
//        centerline[line]=(rightline[line]+leftline[line])/2;
//    }
//    for(line=0;line<69;line++)
//    {
//        BinPixels[line][leftline[line]]=0;
//        BinPixels[line][rightline[line]]=0;
//        BinPixels[line][centerline[line]]=0;
//        if(line>10&&line<30)
//        zxzhi+=centerline[line];
//    }
//    zxzhi/=20;
//    return zxzhi;
//}



//struct _pid{
//    float SetSpeed;//�����趨ֵ
//    float ActualSpeed;//����ʵ��ֵ
//    float err;//����ƫ��ֵ
//    float err_next;//������һ��ƫ��ֵ
//    float err_last;//��������ǰ��ƫ��ֵ
//    float Kp, Ki, Kd;//������������֡�΢��ϵ��
//}pid;
//
//void PID_init(){
//    pid.SetSpeed = 0.0;
//    pid.ActualSpeed = 0.0;
//    pid.err = 0.0;
//    pid.err_last = 0.0;
//    pid.err_next = 0.0;
//    //�����������ֵ���Ӷ��ﵽ���Ч��
//    pid.Kp = 2;
//    pid.Ki = 0;
//    pid.Kd = 0.1;
//}
//
//float PD_zx(float zxzhi)
//{
//    float incrementSpeed;
//    pid.SetSpeed = 92;
//    pid.ActualSpeed=zxzhi;
//    pid.err = pid.SetSpeed - pid.ActualSpeed;
//    incrementSpeed = pid.Kp*(pid.err - pid.err_next) + pid.Kd*(pid.err - 2 * pid.err_next + pid.err_last);//���������
//
//    pid.err_last = pid.err_next;
//    pid.err_next = pid.err;
//    return incrementSpeed;
//}





