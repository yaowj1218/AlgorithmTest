//
//  AVL Tree.h
//  AlgorithmTest

//  算法      平均          最差
//  空间		O(n)        O(n)
//  搜索		O(log n)	O(log n)
//  插入		O(log n)	O(log n)
//  删除		O(log n)	O(log n)

//  Created by 姚文杰 on 2017/4/20.
//  Copyright © 2017年 姚文杰. All rights reserved.
//
#pragma once
#include <iostream>
#include <assert.h>
#include "Tree_Node.h"

using namespace std;


class CAVLTree {
private:
    int getHeight(AVLTree);
    void setHeight(AVLTree,int);
    AVLTree SingleRightRotate(AVLTree);
    AVLTree SingleLeftRotate(AVLTree);
    AVLTree DoubleRightRotate(AVLTree);
    AVLTree DoubleLeftRotate(AVLTree);
    
public:
    CAVLTree();
    ~CAVLTree();
    void createAVLTree(int data[], int n);
    AVLTree insertNode(AVLTree T, int data);
    AVLTree deleteNode(AVLTree T,int data);
    AVLTree searchNode(AVLTree T, int data);
    void inOrder(AVLTree T);
    AVLTree getMaxNode(AVLTree);
    AVLTree getMinNode(AVLTree);
    void deleteTree(AVLTree T);
    AVLTree T;
};

CAVLTree::CAVLTree() {
    T = NULL;
}

CAVLTree::~CAVLTree() {
    deleteTree(T);
}

void CAVLTree::createAVLTree(int data[], int n) {
    if (T) {
        cout << "Has been created~" << endl;
        return;
    }
    if (!n) {
        T = NULL;
        return;
    }
    for (int i = 0; i < n; i++) {
        T = insertNode(T, data[i]);
    }
    return;
}

AVLTree CAVLTree::insertNode(AVLTree T, int data) {
    
    if (T == NULL) {
        
        Tree_Node *pNewNode = new Tree_Node;    //创建一个新 Node
        pNewNode->data = data;
        pNewNode->left = NULL;
        pNewNode->right = NULL;
        pNewNode->height = 1;

        T = pNewNode;
        return T;
    }
    
    if (data == T->data) {
        cout << " 重复！" << endl;
        return T;
    }
    
    if (data < T->data) {           //如果小 在左边插入
        T->left = insertNode(T->left, data);
        
        if (getHeight(T->left) - getHeight(T->right) > 1) {     //比较左右高度，如果大于1 则不平衡
            
            if (data < T->left->data) {                         //如果是小于 则代表在左子树的左边（左左）插入节点破坏的平衡，就应该选择右旋转
                T = SingleRightRotate(T);
            }
            else {                                              //否则代表在左子树的右边插入节点（左右）破坏的平衡，就应该选择两次旋转
                T = DoubleRightRotate(T);
            }
        }
    }
    
    if (data > T->data) {
        T->right = insertNode(T->right, data);
        if (getHeight(T->right) - getHeight(T->left) > 1) {
            if (data > T->data) {
                T = SingleLeftRotate(T);
            }
            else {
                T = DoubleLeftRotate(T);
            }
        }
    }
    
    setHeight(T, max(getHeight(T->left), getHeight(T->right)) + 1); //每次插完 从新算一遍高度
    
    return T;
}

AVLTree CAVLTree::searchNode(AVLTree T, int data) {
    if (!T) {
        return NULL;
    }
    if (data == T->data) {
        return T;
    }
    if (data < T->data) {
        return searchNode(T->left, data);
    }
    else {
        return searchNode(T->right, data);
    }
}

void CAVLTree::inOrder(AVLTree T) {
    if (!T) {
        return;
    }
    else {
        
        inOrder(T->left);
        cout << T->data << " ";
        inOrder(T->right);
    }
}

AVLTree CAVLTree::getMaxNode(AVLTree T) {
    if (!T) {
        return T;
    }
    AVLTree tempNode = T;
    while (tempNode->right) {
        tempNode = tempNode->right;
    }
    return tempNode;
}

AVLTree CAVLTree::getMinNode(AVLTree T) {
    if (!T) {
        return T;
    }
    AVLTree tempNode = T;
    while (tempNode->left) {
        tempNode = tempNode->left;
    }
    return tempNode;
}

int CAVLTree::getHeight(AVLTree T) {
    return (T == NULL) ? 0 : (T->height);
}

void CAVLTree::setHeight(AVLTree T,int height) {
    T->height = height;
}

AVLTree CAVLTree::SingleRightRotate(AVLTree T) {
    AVLTree xNode = T;
    AVLTree yNode = T->left;
    xNode->left = yNode->right;
    yNode->right = xNode;
    xNode->height = max(getHeight(xNode->left),getHeight(xNode->right)) + 1;
    yNode->height = max(getHeight(xNode->left),getHeight(xNode->right)) + 1;
    return yNode;
}

AVLTree CAVLTree::SingleLeftRotate(AVLTree T) {
    AVLTree xNode = T;
    AVLTree yNode = T->right;
    xNode->right = yNode->left;
    yNode->left = xNode;
    xNode->height = max(getHeight(xNode->left),getHeight(xNode->right)) + 1;
    yNode->height = max(getHeight(xNode->left),getHeight(xNode->right)) + 1;
    return yNode;
}

AVLTree CAVLTree::DoubleRightRotate(AVLTree T) {
    assert(T->left != NULL);
    T->left = SingleLeftRotate(T->left);
    return SingleRightRotate(T);
}

AVLTree CAVLTree::DoubleLeftRotate(AVLTree T) {
    assert(T->right != NULL);
    T->right = SingleRightRotate(T->right);
    return SingleLeftRotate(T);
}

void CAVLTree::deleteTree(AVLTree T)
{
    if (NULL == T)
        return;
    
    deleteTree(T->left);
    deleteTree(T->right);
    delete T;
    T = NULL;
}
