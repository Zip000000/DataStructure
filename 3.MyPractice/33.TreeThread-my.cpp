/*************************************************************************
	> File Name: 32.Treethread.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月02日 星期一 21时42分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#define NORMAL 0
#define THREAD 1
using namespace std;

typedef struct Node {
    int key;
    Node *lchild, *rchild;
    int ltag, rtag;
} Node;

Node *getNewNode(int key) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = key;
    n->lchild = n->rchild = NULL;
    n->ltag = n->rtag = NORMAL;
    return n;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (key == root->key) return root;
    if (key > root->key) root->rchild = insert(root->rchild, key);
    else root->lchild = insert(root->lchild, key);
    return root;
} 

void inorder(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) inorder(root->lchild);
    printf("%d ", root->key);
    if (root->rtag == NORMAL) inorder(root->rchild);
    return ;
}

void build_thread(Node *root) {
    if (root == NULL) return;
    static Node *pre = NULL;
    build_thread(root->lchild);
    
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    }

    if (pre && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }

    pre = root;
    build_thread(root->rchild);
}

Node *LeftMost(Node *p) {
    while (p && p->ltag == NORMAL && p->lchild) {
        p = p->lchild;
    }
    return p;
}

void output(Node *root) {
    if (root == NULL) return;
    Node *p = LeftMost(root);

    while (p) {
        printf("%d ", p->key);

        if (p->rtag == NORMAL) {
            p = LeftMost(p->rchild);
        } else {
            p = p->rchild;
        }
    }
    return ;
}

void clear(Node *root) {

}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    build_thread(root);
    inorder(root);
    cout << endl;
    output(root);
    cout << endl;
    
    
    return 0;
}
