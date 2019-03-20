//
//  main.c
//  CRC
//
//  Created by Season Liew on 2018/12/26.
//  Copyright © 2018 Season Liew. All rights reserved.
//
#define SIZE_CRC 9
#define SIZE_DATA 23
#include <stdio.h>
#include <stdlib.h>
#include "src.h"


int main(int argc, const char * argv[]) {
    int ori[SIZE_DATA]={1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0};
    int crc[SIZE_CRC]={1,1,0,0,1,0,1,1,0};
    CRC(ori, sizeof(ori)/sizeof(int), crc, sizeof(crc)/sizeof(int));
    return 9;
}
