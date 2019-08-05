/*************************************************************************
	> File Name: 0.BinTreeByList.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月27日 星期六 10时05分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>



#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *lchild, *rchild;
} BinTreeNode;
/*
BinTreeNode * createBinTreeByGLists(char *gLists, int nodeQuantity);
void preOrderTraverse(BinTreeNode *node);
void inOrderTraverse(BinTreeNode *node);
void postOrderTraverse(BinTreeNode *node);
*/
//根据广义表创建二叉树
BinTreeNode * createBinTreeByGLists(char *gLists, int nodeQuantity) {
    BinTreeNode *rootNode = NULL;
    BinTreeNode *currNode = NULL;

    //创建指针数组作为栈结构
    BinTreeNode **stack = (BinTreeNode **) malloc(sizeof(BinTreeNode *) * nodeQuantity);
    int top = -1;

    int flag = 0;
    const int START_LEFT_CHILD = 1, START_RIGHT_CHILD = 2;

    int index = 0;

    char c = gLists[index];

    while (c != '\0') {

        switch (c) {
            case '(':
                stack[++top] = currNode;
                flag = START_LEFT_CHILD;
                break;
            case ',':
                flag = START_RIGHT_CHILD;
                break;
            case ')':
                top--;
                break;
            case ' ':
                break;
            default:
                currNode = (BinTreeNode *) malloc(sizeof(BinTreeNode));
                currNode->data = c;
                currNode->lchild = currNode->rchild = NULL;

                if (rootNode == NULL) {
                    rootNode = currNode;
                } else {
                    switch (flag) {
                        case START_LEFT_CHILD:
                            stack[top]->lchild = currNode;
                            break;
                        case START_RIGHT_CHILD:
                            stack[top]->rchild = currNode;
                            break;
                    }
                }
        }

        c = gLists[++index];
    }

    //释放
    free(stack);

    return rootNode;
}

//前序遍历
void preOrderTraverse(BinTreeNode *node) {
    if (node != NULL) {
        printf("%c", node->data);

        preOrderTraverse(node->lchild);

        preOrderTraverse(node->rchild);
    }
}

//中序遍历
void inOrderTraverse(BinTreeNode *node) {
    if (node != NULL) {
        inOrderTraverse(node->lchild);

        printf("%c", node->data);

        inOrderTraverse(node->rchild);
    }
}

//后序遍历
void postOrderTraverse(BinTreeNode *node) {
    if (node != NULL) {
        postOrderTraverse(node->lchild);

        postOrderTraverse(node->rchild);

        printf("%c", node->data);
    }
}

int main(int argc, const char * argv[]) {
    char gLists[] = "(A (B (C, D), E ( , F)) )";

    BinTreeNode *rootNode = createBinTreeByGLists(gLists, 6);

    printf("pre order: ");
    preOrderTraverse(rootNode);
    printf("\nin order: ");
    inOrderTraverse(rootNode);
    printf("\npost order: ");
    postOrderTraverse(rootNode);

    return 0;
}

