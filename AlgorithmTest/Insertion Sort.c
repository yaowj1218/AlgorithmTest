//
//  Insertion Sort.c
//  AlgorithmTest
//
//  Created by 姚文杰 on 2017/4/3.
//  Copyright © 2017年 姚文杰. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#define NUM 10

void insertion_sort(int a[], int i) {
    int k, n;
    for (; i<NUM-1; i++) {
        for (n = i; n >= 0; n--) {
            if (a[n]>a[n + 1]) {
                k = a[n];
                a[n] = a[n + 1];
                a[n + 1] = k;
            }
            else break;
            
        }
    }
}

