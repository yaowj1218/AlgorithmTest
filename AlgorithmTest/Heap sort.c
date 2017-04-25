//
//  Heap sort.c
//  AlgorithmTest
//
//
//  时间复杂度 O(nlogn)
//  最优时间复杂度 O(nlogn)
//  平均时间复杂度 O(nlogn)
//
//
//  Created by 姚文杰 on 2017/4/12.
//  Copyright © 2017年 姚文杰. All rights reserved.
//

#include <stdio.h>

void swap(int arr[],int max,int index){
    int temp = arr[index];
    arr[index]=arr[max];
    arr[max]=temp;
}

void buildMaxheap(int arr[],int index,int size){
    int iMax,iRight,iLeft;
    while (1) {
        iMax=index;
        iLeft=2*index+1;
        iRight=2*(index+1);
        
        if(arr[iMax]<arr[iLeft]&&iLeft<size){
            iMax=iLeft;
        }//先判断是否在范围内 再比较
        
        if(arr[iMax]<arr[iRight]&&iRight<size){
            iMax=iRight;
        }//先判断是否在范围内 再比较
        
        if(iMax!=index){
            swap(arr,iMax,index);
            index=iMax;
        }else
            break;
    }
}
