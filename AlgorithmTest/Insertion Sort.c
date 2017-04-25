//
//  Insertion Sort.c
//  AlgorithmTest
//
//  排序时：
//  平均时间复杂度 O(n^2)
//  最优时间复杂度 O(n)
//  最差时间复杂度 O(n^2)

//  Created by 姚文杰 on 2017/4/3.
//  Copyright © 2017年 姚文杰. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#define NUM 10

void insertion_sort(int a[], int i) {
    int k, n;
    for (; i<NUM-1; i++) {                   //从前向后遍历
        for (n = i; n >= 0; n--) {          //从已排序的末尾和下一个未排序的比较开始 向前比较 放到正确的位置
            if (a[n]>a[n + 1]) {
                k = a[n];
                a[n] = a[n + 1];
                a[n + 1] = k;
            }
            else break;
            
        }
    }
}

