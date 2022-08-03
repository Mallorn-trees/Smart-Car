/*
 * process_auxiliary.c
 *
 *  Created on: Aug 2, 2022
 *      Author: hp
 */

#include "process_auxiliary.h"

float parameterA,parameterB;
float pianfangleft,pianfangright,pianfangmid;

void advanced_regression(int type, int startline1, int endline1, int startline2, int endline2)
{
    int i = 0;
    int sumlines1 = endline1 - startline1;
    int sumlines2 = endline2 - startline2;
    int sumX = 0;
    int sumY = 0;
    float averageX = 0;
    float averageY = 0;
    float sumUp = 0;
    float sumDown = 0;
    if (type == 0)  //拟合中线
    {
        /**计算sumX sumY**/
        for (i = startline1; i < endline1; i++)
        {
            sumX += i;
            sumY += LCenter[i];
        }
        for (i = startline2; i < endline2; i++)
        {
            sumX += i;
            sumY += LCenter[i];
        }
        averageX =(float)( sumX / (sumlines1 + sumlines2));     //x的平均值
        averageY = (float)(sumY / (sumlines1 + sumlines2));     //y的平均值
        for (i = startline1; i < endline1; i++)
        {
            sumUp += (LCenter[i] - averageY) * (i - averageX);
            sumDown += (i - averageX) * (i - averageX);
        }
        for (i = startline2; i < endline2; i++)
        {
            sumUp += (LCenter[i] - averageY) * (i - averageX);
            sumDown += (i - averageX) * (i - averageX);
        }
        if (sumDown == 0) parameterB = 0;
        else parameterB = sumUp / sumDown;
        parameterA = averageY - parameterB * averageX;

    }
    else if (type == 1)     //拟合左线
    {
        /**计算sumX sumY**/
        for (i = startline1; i < endline1; i++)
        {
            sumX += i;
            sumY += L_black[i];
        }
        for (i = startline2; i < endline2; i++)
        {
            sumX += i;
            sumY += L_black[i];
        }
        averageX =(float)( sumX / (sumlines1 + sumlines2));     //x的平均值
        averageY = (float)(sumY / (sumlines1 + sumlines2));     //y的平均值
        for (i = startline1; i < endline1; i++)
        {
            sumUp += (L_black[i] - averageY) * (i - averageX);
            sumDown += (i - averageX) * (i - averageX);
        }
        for (i = startline2; i < endline2; i++)
        {
            sumUp += (L_black[i] - averageY) * (i - averageX);
            sumDown += (i - averageX) * (i - averageX);
        }
        if (sumDown == 0) parameterB = 0;
        else parameterB = sumUp / sumDown;
        parameterA = averageY - parameterB * averageX;
    }
    else if (type == 2)         //拟合右线
    {
        /**计算sumX sumY**/
        for (i = startline1; i < endline1; i++)
        {
            sumX += i;
            sumY += R_black[i];
        }
        for (i = startline2; i < endline2; i++)
        {
            sumX += i;
            sumY += R_black[i];
        }
        averageX =(float)( sumX / (sumlines1 + sumlines2));     //x的平均值
        averageY = (float)(sumY / (sumlines1 + sumlines2));     //y的平均值
        for (i = startline1; i < endline1; i++)
        {
            sumUp += (R_black[i] - averageY) * (i - averageX);
            sumDown += (i - averageX) * (i - averageX);
        }
        for (i = startline2; i < endline2; i++)
        {
            sumUp += (R_black[i] - averageY) * (i - averageX);
            sumDown += (i - averageX) * (i - averageX);
        }
        if (sumDown == 0) parameterB = 0;
        else parameterB = sumUp / sumDown;
        parameterA = averageY - parameterB * averageX;
    }

}


void regression(int type, int startline, int endline)//最小二乘法拟合曲线，分别拟合中线，左线，右线,type表示拟合哪几条线   xy 颠倒
{
    int i = 0;
    int sumlines = endline - startline;
    int sumX = 0;
    int sumY = 0;
    float averageX = 0;
    float averageY = 0;
    float sumUp = 0;
    float sumDown = 0;
    if (type == 0)      //拟合中线
    {
        for (i = startline; i < endline; i++)
        {
            sumX += i;
            sumY += LCenter[i];
        }
        if (sumlines != 0)
        {
            averageX = (float)(sumX / sumlines);     //x的平均值
            averageY =(float)( sumY / sumlines);     //y的平均值
        }
        else
        {
            averageX = 0;     //x的平均值
            averageY = 0;     //y的平均值
        }
        for (i = startline; i < endline; i++)
        {
            sumUp += (LCenter[i] - averageY) * (i - averageX);
            sumDown += (i - averageX) * (i - averageX);
        }
        if (sumDown == 0) parameterB = 0;
        else parameterB = sumUp / sumDown;
        parameterA = averageY - parameterB * averageX;
    }
    else if (type == 1)//拟合左线
    {
        for (i = startline; i < endline; i++)
        {
            sumX += i;
            sumY += L_black[i];
        }
        if (sumlines == 0) sumlines = 1;
        averageX = (float)(sumX / sumlines);     //x的平均值
        averageY =(float)( sumY / sumlines);     //y的平均值
        for (i = startline; i < endline; i++)
        {
            sumUp += (L_black[i] - averageY) * (i - averageX);
            sumDown += (i - averageX) * (i - averageX);
        }
        if (sumDown == 0) parameterB = 0;
        else parameterB = sumUp / sumDown;
        parameterA = averageY - parameterB * averageX;
    }
    else if (type == 2)//拟合右线
    {
        for (i = startline; i < endline; i++)
        {
            sumX += i;
            sumY += R_black[i];
        }
        if (sumlines == 0) sumlines = 1;
        averageX = (float)(sumX / sumlines);     //x的平均值
        averageY =(float)( sumY / sumlines);     //y的平均值
        for (i = startline; i < endline; i++)
        {
            sumUp += (R_black[i] - averageY) * (i - averageX);
            sumDown += (i - averageX) * (i - averageX);
        }
        if (sumDown == 0) parameterB = 0;
        else parameterB = sumUp / sumDown;
        parameterA = averageY - parameterB * averageX;

    }
}

//求两数之差绝对值开始
int My_Abs(int a, int b)
{

            if ((a - b) > 0)

                return ((int)(a - b));
            else return ((int)(b - a));
}

void pianfangcal(int begin, int end, int type)
{

    int i = 0;
    if (type == 1)//左线拟合差平方计算
    {
        pianfangleft = 0;
        regression (1, begin, end);
        monileftfuzhi(parameterA, parameterB,(int) begin,(int) end);
        for (i = begin; i <= end; i++)
        {
            pianfangleft = pianfangleft + (L_black[i] - monileft[i]) * (L_black[i] - monileft[i]);
        }
        pianfangleft = pianfangleft / (end - begin + 1);
    }
    if (type == 2)//右线拟合差平方计算
    {
        pianfangright = 0;
        regression(2, begin, end);
        monirightfuzhi(parameterA, parameterB,(int) begin,(int) end);
        for (i = begin; i <= end; i++)
        {
            pianfangright = pianfangright + (R_black[i] - moniright[i]) * (R_black[i] - moniright[i]);
        }
        pianfangright = pianfangright / (end - begin + 1);
    }
    if (type == 0)//右线拟合差平方计算
    {
        pianfangmid = 0;
        regression(0, begin, end);
        monizhongfuzhi(parameterA, parameterB, (int)begin, (int)end);
        int fangjun = 0;
        int junfang = 0;
        for (i = begin; i <= end; i++)
        {
            fangjun = fangjun + (LCenter[i]) * (LCenter[i]);
        }
        fangjun= fangjun / (end - begin + 1);
        for (i = begin; i <= end; i++)
        {
            junfang = junfang + (LCenter[i]);
        }
        junfang = junfang / (end - begin + 1);
        junfang = junfang * junfang;
        pianfangmid = fangjun - junfang;
    }

}

void monileftfuzhi(float A, float B, int start_point, int end_point)
{
    int m;
    for (m = start_point; m <= end_point; m++)
    {
        if((B * m + A)>=255) monileft[m]=255;
        if((B * m + A)<=0) monileft[m]=0;
        else if(0<(B * m + A)&&(B * m + A)<255)monileft[m] = (int)(B * m + A);
    }
}

void monirightfuzhi(float A, float B, int start_point, int end_point)
{
    int m;
    for (m = start_point; m <= end_point; m++)
    {
        if((B * m + A)>=255) moniright[m]=255;
        if((B * m + A)<=0) moniright[m]=0;
        else if(0<(B * m + A)&&(B * m + A)<255)moniright[m] = (int)(B * m + A);
    }
}

void monizhongfuzhi(float A, float B, int start_point, int end_point)
{
    int m;
    for (m = start_point; m <= end_point; m++)
    {
        if ((B * m + A) >= 255) monimiddle[m] = 255;
        if ((B * m + A) <= 0) monimiddle[m] = 0;
        else if (0 < (B * m + A) && (B * m + A) < 255) monimiddle[m] = (int)(B * m + A);
    }
}


