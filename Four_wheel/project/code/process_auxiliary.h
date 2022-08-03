/*
 * process_auxiliary.h
 *
 *  Created on: Aug 2, 2022
 *      Author: hp
 */

#ifndef PROCESS_AUXILIARY_H_
#define PROCESS_AUXILIARY_H_

#include "zf_common_headfile.h"

void advanced_regression(int type, int startline1, int endline1, int startline2, int endline2);
void regression(int type, int startline, int endline);
int My_Abs(int a, int b);
void pianfangcal(int begin, int end, int type);
void monileftfuzhi(float A, float B, int start_point, int end_point);
void monirightfuzhi(float A, float B, int start_point, int end_point);
void monizhongfuzhi(float A, float B, int start_point, int end_point);


extern uint8_t LCenter[70], L_black[70], R_black[70];
extern uint8_t monileft[70], moniright[70],monimiddle[70];



#endif /* PROCESS_AUXILIARY_H_ */
