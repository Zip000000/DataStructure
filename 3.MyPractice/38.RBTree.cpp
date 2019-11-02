/*************************************************************************
	> File Name: 37.RBTree.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月02日 星期三 11时45分36秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2
struct Node {
    int key, color;
    struct Node *lchild, *rchild;
};
Node _NIL, *NIL = &_NIL;
void init_NIL() {
    NIL->key = 0;
    NIL->lchild = NIL->rchild = NIL;
    NIL->color = BLACK;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->color = RED;
    return p;
}
int hasRedChild(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}
Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}
Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;

}
Node *insert_maintain(Node *root) {
    if (!hasRedChild(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!hasRedChild(root->lchild) && !hasRedChild(root->rchild)) return root;
        root->color = RED;
        root->lchild->color = root->rchild->color = BLACK;
        return root;
    }
    //只有一个红色子孩子
    if (root->lchild->color == RED) {
        if (!hasRedChild(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (!hasRedChild(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
        
    }
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = __insert(root->lchild, key);
    else root->rchild = __insert(root->rchild, key);
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("%d [%d, %d] %s\n", root->key, root->lchild->key, root->rchild->key, (root->color ? "BLACK" : "RED"));
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d %d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: break;
        }
        output(root);
    }
    
    
    
    return 0;
}
