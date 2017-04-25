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
#include "Heap sort.c"
#include "Binary sort tree.h"
#include "AVL Tree.h"
#include <iostream>
#define NUM 10


int main(int argc, const char * argv[]) {
    int a[NUM] = { 9,3,5,7,2,4,17,8,1,-1 };
    int b[NUM];
    
    /*插入排序*/
//    insertion_sort(a, 0);// 起始位置
    
    /*归并排序*/
//    MergeSort(a, b, 0, NUM-1);//注意-1
    
    /*堆排序*/
//    buildMaxheap(arr,0,NUM);
    
    /*二叉树排序*/
//    creat_tree(a,NUM);
//    for (int i = 0; i<NUM; i++)
//        printf("%d ", a[i]);
    
    /*平衡二叉排序*/
    CAVLTree *obj=new CAVLTree();
    obj->createAVLTree(a, NUM);
    obj->inOrder(obj->T);
    
    
    printf("\nSuccess\n");
    system("pause");
    return 0;
}
