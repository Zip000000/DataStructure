/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月20日 星期五 12时35分40秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}


Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NULL) return root;
    if (root->key == key) {
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        }
    } else {
        Node *temp = predecessor(root);
        root->key = temp->key;
        root->lchild = erase(root->lchild, temp->key);
        return root;
    }
    if (root->key > key) root->lchild = erase(root->lchild, key);
    else root->rchild = erase(root->rchild, key);
}

void __in_order(Node *root) {
    if (root == NULL) return;
    __in_order(root->lchild);
    printf("%d ", root->key);
    __in_order(root->rchild);
    return ;
}

void in_order(Node *root) {

    printf("in ordered output : ");
    __in_order(root);
    printf("\n");
}

void clear(Node *node) {
    if (node == NULL) return;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}
int main() {
    
    int op, val;
    Node *root = NULL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
        }
        in_order(root);
    }
    clear(root);
    return 0;
}
