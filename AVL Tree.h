//
//  AVL Tree.h
//  AlgorithmTest
//
//  Created by 姚文杰 on 2017/4/20.
//  Copyright © 2017年 姚文杰. All rights reserved.
//
#pragma once
#include <iostream>
using namespace std;

typedef struct Tree_Node {
    int data;
    Tree_Node* left;
    Tree_Node* right;
    int bf;
    int height;
}Tree_Node,*AVLTree;

class CAVLTree {
private:
    int getHeight(AVLTree, int);
    
    AVLTree SingleRightRotate(AVLTree);
    AVLTree SingleLeftRotate(AVLTree);
    AVLTree DoubleRightRotate(AVLTree);
    AVLTree DoubleleftRotate(AVLTree);
    
public:
    CAVLTree();
    ~CAVLTree();
    void createAVLTree(int data, int n);
    AVLTree insertNode(AVLTree T, int data);
    AVLTree deleteNode(AVLTree T,int data);
    AVLTree searchNode(AVLTree T, int data);
    void preOrder(AVLTree T);
    AVLTree getMaxNode(AVLTree);
    AVLTree getMinNode(AVLTree);
    
    AVLTree T;
};

CAVLTree::CAVLTree() {
    T = NULL;
}

CAVLTree::~AVLTree() {
    deleteNode(T);
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
    Tree_Node *pNewNode = new Tree_Node;
    pNewNode->data = data;
    pNewNode->left = NULL;
    pNewNode->right = NULL;
    pNewNode->hight = 1;
    
    if (T == NULL) {
        T = pNewNode;
        return T;
    }
    
    if (data == T->data) {
        cout << "chongfu" << endl;
        return T;
    }
    
    if (data < T->data) {
        T->left = insertNode(T->left, data);
        if (getHeight(T->left) - getHeight(T->right) > 1) {
            if (data < T->left->data) {
                T = SingleRightRotate(T);
            }
            else {
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
                T = DoubleleftRotate(T);
            }
        }
    }
    
    setHeight(T, max(getHeight(T->left), getHeight(T->right)) + 1);
    
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

void CAVLTree::preOrder(AVLTree T) {
    if (!T) {
        cout << "NULL" << endl;
    }
    else {
        cout << T->data << " ";
        preOrder(T->left);
        preOrder(T->right);
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
    xNode->height = max(getHeight(xNode->left, xNode->right)) + 1;
    yNode->height = max(getHeight(yNode->left, yNode->right)) + 1;
    return yNode;
}

AVLTree CAVLTree::SingleLeftRotate(AVLTree T) {
    AVLTree xNode = T;
    AVLTree yNode = T->right;
    xNode->right = yNode->left;
    yNode->left = xNode;
    xNode->height = max(getHeight(xNode->left, xNode->right)) + 1;
    yNode->height = max(getHeight(yNode->left, yNode->right)) + 1;
    return yNode;
}

AVLTree CAVLTree::DoubleRightRotate(AVLTree T) {
    assert(T->left == NULL);
    T->left = SingleLeftRotate(T->left);
    return SingleRightRotate(T);
}

AVLTree CAVLTree::DoubleLeftRotate(AVLTree T) {
    assert(T->right == NULL);
    T->right = SingleRightRotate(T->right);
    return SingleLeftRotate(T);
}

void CAVLTree::deleteTree(AVLTree T)
{
    if (NULL == T)
        return;
    
    deleteTree(T->left);
    deleteTree(T->right);
    delete t;
    T = NULL;
}
