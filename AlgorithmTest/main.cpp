//
//  main.cpp
//  AlgorithmTest
//
//  Created by 姚文杰 on 2017/4/3.
//  Copyright © 2017年 姚文杰. All rights reserved.
//

#include <stdio.h>
#include "Merge sort.hpp"
#include "Insertion Sort.c"
#include <iostream>
#define NUM 10


int main(int argc, const char * argv[]) {
    int a[NUM] = { 9,3,5,7,2,4,17,8,1,0 };
    int b[NUM];
    insertion_sort(a, 0);// 起始位置
    MergeSort(a, b, 0, NUM-1);//注意-1
    for (int i = 0; i<NUM; i++)
        printf("%d ", a[i]);
    printf("\nSuccess\n");
    system("pause");
    return 0;
}
