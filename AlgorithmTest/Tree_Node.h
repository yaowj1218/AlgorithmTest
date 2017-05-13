//
//  Tree_Node.h
//  AlgorithmTest
//
//  Created by 姚文杰 on 2017/4/25.
//  Copyright © 2017年 姚文杰. All rights reserved.
//

#ifndef Tree_Node_h
#define Tree_Node_h

typedef struct Tree_Node {
    int data;
    Tree_Node* left;
    Tree_Node* right;
    int bf;
    int height;
}Tree_Node,*AVLTree;


#endif /* Tree_Node_h */
