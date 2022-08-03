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

int leftline[120];  //赛道左边界
int rightline[120];  //赛道右边界
int centerline[120]; //赛道中间线

int road_width[120];//道路宽度   这里的80是我只扫描了80行
void image_scan()                  //1白        0黑
{
    int line=0;     //行
    int list=0;     //列
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
    //第一次扫线，获取0-50行左右线的值
    for (hang = 0; hang < 50; hang++)
    {
        for (lie = zhongold; lie >= 1; lie--)
        {
            if (lie >= (int)185) lie = 184;
            if (BinPixels[hang][ lie - 1] == 0 && BinPixels[hang][ lie] == 0 && BinPixels[hang][lie + 1] == 1) //黑白
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
        //下一行的扫线在上一行的基础上向左右扫
        zhongold = (int)((L_black[hang] + R_black[hang]) / 2);
    }
    for (hang = 0; hang < 50; hang++)
    { LCenter[hang] = (unsigned char)((L_black[hang] + R_black[hang]) / 2); }

    /*二次扫线*/
    duanhang0 = 0;
    duanhang1 = 0;
    for (hang = 1; hang < 50; hang++)  //扫断点0
    {
    /*
    断行0的原理:由于摄像头视角，呈现出的赛道应该是近大远小的，如果远
    处的行 宽度比近处的大，那么认为出现第一个断行。(大家可以想一下十
    字路口的下方 赛道宽度变宽)
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
    如果扫描到断行0，那么从断行0开始的图像可能有问题，
    所以这里选择固定终止往下扫线，寻找断行1的存在。
    (断行1的原理，当宽度再次变小且小于断行0处的宽度，
    认为是正确的断行1，大家可以想一下十字路口的上半段)


   */
        advanced_regression(0, duanhang0 - 9, duanhang0 - 7, duanhang0 - 5, duanhang0 - 3); //显示断行处斜率
        zhongold2 = LCenter[duanhang0 - 7];
        for (hang = (int)(duanhang0 + 3); hang < 50; hang++)  //固定中值扫线
        {
            for (lie = (int)zhongold2; lie >= 1; lie--)  //扫右线
            {
                if (lie >= 185) lie = 184;
                if (BinPixels[hang][ lie - 1] == 0 && BinPixels[hang][ lie] == 0 && BinPixels[hang][ lie + 1] == 1) //白黑黑
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
            for (lie = (int)zhongold2; lie < 185; lie++)  //扫左线
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
    for (hang = (int)(duanhang0 + 3); hang < 50; hang++)//扫断点1
    {
     /*
    计算是否存在断行1
    */
        if ((L_black[hang] - R_black[hang]) < duanhangju-15&&L_black[hang]<=180&&R_black[hang]>=5)
        {
            duanhang1 = (signed short int)hang;
          //  SetText("    找到断行1    " + duanhang1);
          //   SetText("    duanhangju1    " + calkuan[duanhang1]);
            break;
        }
    }
    if (duanhang0 > 10 && duanhang1 != 0)
    {
      /*
    找到断行1，开始进入二次扫线模式
    二次扫线思路:从断行1处开始使用断行0的中值进行扫线，动态继承中值往下扫。
     */
        zhongold2 = LCenter[duanhang0 - 7];

        int gudingtime = 1;
        for (hang = (int)(duanhang1); hang < 50; hang++)  //二次扫线
        {
            for (lie = (int)zhongold2; lie >= 1; lie--)  //扫右线
            {
                if (lie >= 185) lie = 184;
                if (BinPixels[hang][ lie - 1] == 0 && BinPixels[hang][ lie] == 0 && BinPixels[hang][lie + 1] == 1) //白黑黑
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
            for (lie = (int)zhongold2; lie < 185; lie++)  //扫左线
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

    //  终止
    //存入显示数组中
    for (hang = 0; hang < 69; hang++)  //去掉杂点
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
            //也就是说二十行一下是不会break的
            if (break_hangshu >= 20)    //防止在一开始就break
            {
                break;
            }
        }
        if ((BinPixels[j][ LCenter[j]]) == 0 && (BinPixels[j + 1][ LCenter[j+1]]) == 0 && (BinPixels[j + 2][ LCenter[j+2]]) == 0 && (BinPixels[j + 3][ LCenter[j+3]]) == 0 /* && (huandao_memory == 4 || huandao_memoryforleft == 4)*/)
        {
            break_hangshu = (int16)j;
            //last_break_hangshu = break_hangshu;
            //也就是说二十行一下是不会break的
            if (break_hangshu >= 20)    //防止在一开始就break
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
            //计算左边线的最终有效行数
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
            //计算右边线的最终有效行数
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
        //求开始点
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
//      下面的代码是用来计算环岛的相关参数，进行辅助判断。
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
//    if (turepodaoflag == 0 && rukuflag == 0)  //坡道不退出  入库刹车10帧后自行退出
//    {
//        for (j = 0; j <= 185; j++)  //退出
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

    //LWL的勾巴中间扫线
//int leftline[120];  //赛道左边界
//int rightline[120];  //赛道右边界
//int centerline[120]; //赛道中间线
//int road_width[120];//道路宽度   这里的80是我只扫描了80行
//float image_scan()                  //1白        0黑
//{
//    float zxzhi=0;
//    int line=0;     //行
//    int list=0;     //列
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
//    float SetSpeed;//定义设定值
//    float ActualSpeed;//定义实际值
//    float err;//定义偏差值
//    float err_next;//定义上一个偏差值
//    float err_last;//定义最上前的偏差值
//    float Kp, Ki, Kd;//定义比例、积分、微分系数
//}pid;
//
//void PID_init(){
//    pid.SetSpeed = 0.0;
//    pid.ActualSpeed = 0.0;
//    pid.err = 0.0;
//    pid.err_last = 0.0;
//    pid.err_next = 0.0;
//    //可设置下面的值，从而达到最佳效果
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
//    incrementSpeed = pid.Kp*(pid.err - pid.err_next) + pid.Kd*(pid.err - 2 * pid.err_next + pid.err_last);//计算出增量
//
//    pid.err_last = pid.err_next;
//    pid.err_next = pid.err;
//    return incrementSpeed;
//}





