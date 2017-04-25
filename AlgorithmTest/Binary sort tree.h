//
//  Binary sort tree.h
//  AlgorithmTest
//
//  最好平均查找长度 O(log n)
//  最差平均查找长度 (n+1)/2
//
//  Created by 姚文杰 on 2017/4/18.
//  Copyright © 2017年 姚文杰. All rights reserved.
//

#ifndef Binary_sort_tree_h
#define Binary_sort_tree_h

#include<iostream>
#include "Tree_Node.h"

using namespace std;

Tree_Node* insert_tree(Tree_Node *t,int data){
    if(t==NULL){                //如果树空 创建一个根节点
        t=new Tree_Node();
        t->left=t->right=NULL;
        t->data=data;
        return t;
    }
    if(t->data==NULL){
        t->data=data;
        return t;
    }
    if(data<t->data){                       //递归
      t->left=insert_tree(t->left,data);
    }
    else{
      t->right=insert_tree(t->right,data);
    }
    return t;
}

void print_tree(Tree_Node* t){
  if (t){
    print_tree(t->left);
    printf("%d\n",t->data );
    print_tree(t->right);
  }
}

Tree_Node* creat_tree(int arr[],int n){
    Tree_Node* t;
    Tree_Node* temp;
    temp=new Tree_Node();
    t=temp;
    temp->data=NULL;
  for(int i=0;i<n;i++){
    temp=insert_tree(temp,arr[i]);
  }
    print_tree(t);
  return t;
}


#endif /* Binary_sort_tree_h */
