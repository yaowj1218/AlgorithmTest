//
//  Merge sort.cpp
//  AlgorithmTest
//
//  平均时间复杂度 O(nlogn)
//  最优时间复杂度 O(nlogn)
//  最差时间复杂度 O(nlogn)
//
//  Created by 姚文杰 on 2017/4/3.
//  Copyright © 2017年 姚文杰. All rights reserved.
//

#include <iostream>
#define NUM 10

void Merge(int sourceArr[], int temp[], int start, int end, int mid) {
    //i 为第一个数组开始位置，j 为第二个数组开始位置，k 为 temp[]开始位置
    int i = start, j = mid + 1, k = start;
    while (i <=mid && j <= end) {               //两个数组按顺序合并
        if (sourceArr[i]<sourceArr[j])
            temp[k++] = sourceArr[i++];
        else
            temp[k++] = sourceArr[j++];
    }
    while (i <= mid) {                          //若其中一个数组多
        temp[k++] = sourceArr[i++];
    }
    while (j <= end) {
        temp[k++] = sourceArr[j++];
    }
    for (i = start; i <= end; i++)
        sourceArr[i] = temp[i];
    for (i = 0; i <= end; i++) {
        printf("%d ", sourceArr[i]);
    }
    printf("\n");
}

void MergeSort(int sourceArr[], int temp[], int start, int end) {
    int mid;
    if (start<end) {
        mid = (start + end) / 2;
        MergeSort(sourceArr, temp, start, mid); //将原本的数组一分为2
        MergeSort(sourceArr, temp, mid + 1, end);
        Merge(sourceArr, temp, start, end, mid);
    }
}



