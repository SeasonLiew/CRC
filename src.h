//
//  src.h
//  CRC
//
//  Created by Season Liew on 2018/12/26.
//  Copyright © 2018 Season Liew. All rights reserved.
//
#include <string.h>
#ifndef src_h
#define src_h
#define ERROR 0;
int pos_firstone(int *data,int begin);
int zero_Stuffing(int *data,int size_data,int a);
void Xor(int i,int *crc,int size_crc,int *data, int size_data);
int add(int a, int b);
int * CRC(int *ori,int size_ori, int *crc,int size_crc);
void print(int arr[],int size_arr);
int cpy(int *a,int size_a,int *b,int size_b);
void printCRC(int arr[],int size_arr, int pos, int total);
//int zeros(int *a,int size_a);
int lastzeros(int *arr, int size_a);
void println(int arr[],int size_arr,int a);
int * CRC(int *ori,int size_ori, int *crc,int size_crc){
    if(size_ori-pos_firstone(ori,0)<size_crc) return ERROR;
    int  lasttime=pos_firstone(ori,0);
    printf("*");
    print(ori, SIZE_DATA);
    printf("\n");
    printCRC(crc, SIZE_CRC, 0, SIZE_DATA);
    while(lasttime+size_crc<=size_ori){
    Xor(pos_firstone(ori,lasttime),crc,size_crc,ori,size_ori);
        lasttime=pos_firstone(ori, lasttime);
        println(ori, size_ori,lasttime-1);
        if(lasttime+size_crc<=size_ori)
        printCRC(crc, size_crc, lasttime, SIZE_DATA);
    }
    printf("the CRC appendix is ");
    for(int i=pos_firstone(ori, lasttime);i<size_ori;i++) printf("%d",ori[i]);
    printf("\n");
    return 0;
}
int add(int a, int b){
    if( (a==0&&b==0)||(a==1&&b==1)) return 0;
    else return 1;
}
void Xor(int i,int *crc,int size_crc,int *data, int size_data){
    int l=i;
   
    for(int k=0;k<size_crc;k++){
        data[l]=add(data[l] ,crc[k]);
        l++;
    }
}
int zero_Stuffing(int *data,int size_data,int a){
    int newsize=(size_data+a-lastzeros(data, size_data));
    int neo[newsize];
    cpy(data,size_data,neo,size_data+a);
    for(int i=newsize-1;i>newsize-1-a;i--) neo[i]=0;
   data=neo;
    return newsize;
}

int pos_firstone(int *data,int begin){
    int i=begin;
    for( ;data[i]==0;i++);
    return i;
}
int lastzeros(int *arr, int size_a){
    int j=size_a-1; int i=0;
    for(i=0;arr[j]==0&&j>0;i++) j--;
    return i;
}

int cpy(int *a,int size_a,int *b,int size_b){
    if(size_b<size_a) return -1;
    for(int i=0;i<size_a;i++) b[i]=a[i]; return 0;
}

void print(int arr[],int size_arr){
    int a =size_arr;
    for(int i=0; i<a;i++) printf("%d ",arr[i]);
    
}
void printCRC(int arr[],int size_arr, int pos, int total){
    printf("@");
    for(int i=0; i<pos;i++) printf("--");//print zeros
    print(arr, size_arr);
    for(int i=pos+size_arr; i<total;i++) printf("--");
    printf("\n");
}
void println(int *arr,int size_arr,int a){
    int i=0;
    printf("*");
    for(;i<=a;i++ ) printf("  ");
    for(; i<size_arr;i++) printf("%d ",arr[i]);
    printf("\n");
}
#endif /* src_h */
