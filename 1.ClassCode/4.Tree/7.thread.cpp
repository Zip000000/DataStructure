/*************************************************************************
	> File Name: 7.thread.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月07日 星期三 18时33分43秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <time.h>
using namespace std;

#define NORMAL 0
#define THREAD 1

typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild = NULL;
    p->key = key;
    p->ltag = p->rtag = NORMAL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) root->rchild = insert(root->rchild,key);
    else root->lchild = insert(root->lchild, key);
    return root;
}

void inorder(Node *root) {
    if (root == NULL) return;
    if (root->ltag == NORMAL) inorder(root->lchild);
    printf("%d ", root->key);
    if (root->ltag == NORMAL) inorder(root->rchild);
    
}

void build_thread(Node *root) {
    if (root == NULL) return;
    static Node *pre  = NULL;
    build_thread(root->lchild);
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;

    build_thread(root->rchild);
    return;
}


void clear(Node *root) {
    if (root == NULL) return;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
    return;
}

Node *leftest(Node *p) {
    while (p != NULL && p->ltag == NORMAL && p->lchild != NULL) p = p->lchild;
    return p;
}

void output(Node *root) {
    Node *p = leftest(root);
    while (p != NULL) {
        printf("%d ", p->key);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = leftest(p->rchild);
        }
    }
    printf("\n");
    return;
}

int main() {
    srand(time(0));
    #define  MAX_OP 20
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() %100;
        root = insert(root, val);
    }
    inorder(root);
    printf("\n");

    build_thread(root);
    output(root);
    clear(root);
    
    
    return 0;
}
