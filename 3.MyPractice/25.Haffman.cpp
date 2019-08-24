/*************************************************************************
	> File Name: 25.Haffman.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月24日 星期六 13时40分32秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}

typedef struct Node {
    char ch;  //当前节点所代表的字符
    double p;  //频次
    struct Node *l, *r;
} Node;

typedef struct Data {
    char ch;
    double p;
} Data;
Data arr[MAX_N + 5];

typedef struct Code {
    char ch;
    char *str;
} Code;

typedef struct HaffmanTree {
    Node *root;
    int n;
    Code *codes;
} HaffmanTree;

Node *getNewNode(Data *obj) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->ch = (obj ? obj->ch : 0);
    n->p = (obj ? obj->p : 0);
    n->l = n->r = NULL;
    return n;
}
/*
void insertOnde (Node **arr, int n) {
    for (int j = n; j >= 1; j--) {

    }
}
*/

HaffmanTree *getNewTree(int n) {
    HaffmanTree *tree = (HaffmanTree *)malloc(sizeof(HaffmanTree));
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    tree->root == NULL;
    tree->n = n;
    return tree;
}

int extractCodes(Node *root, Code *codes, int k, int l, char* buff) {
    //只要左子树为空　当前就是叶子节点
    buff[l] = 0;
    if (root->l == NULL && root->r == NULL) {
        codes[k].ch = root->ch;
        codes[k].str = strdup(buff);
        return 1;
    }
    int delta = 0;
    buff[l] = '0';
    delta += extractCodes(root->l, codes, k + delta, l + 1, buff);
    buff[l] = '1';
    delta += extractCodes(root->r, codes, k + delta, l + 1, buff);
    return delta;
}

HaffmanTree *build(Data *arr, int n) {
    Node **nodes = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) {
        nodes[i] = getNewNode(arr + i);
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j >= 1; j--) {
            if (nodes[j]->p > nodes[j - 1]->p) {
                swap(nodes[j], nodes[j - 1]);
                continue;
            } 
            break;
        }
    }
    
    for (int i = n - 1; i >= 1; i--) {
        Node *n = getNewNode(NULL);
        n->l = nodes[i];
        n->r = nodes[i - 1];
        n->p = n->l->p + n->r->p;
        nodes[i - 1] = n;
        for (int j = i - 1; j >= 1; j--) {
            if (nodes[j]->p > nodes[j - 1]->p) {
                swap(nodes[j], nodes[j - 1]);
                continue;
            } 
            break;
        }
    }
    HaffmanTree *tree = getNewTree(n);
    tree->root = nodes[0];
    char *buff = (char *)calloc(sizeof(char), n);
    extractCodes(tree->root, tree->codes, 0, 0, buff);

    free(nodes);
    

    return tree;
    
}


int main() {
    int n;
    scanf("%d", &n);
    char str[10];
    for (int i = 0; i < n; i++) {
        scanf("%s%lf", str, &arr[i].p);
        arr[i].ch = str[0];
    }

    HaffmanTree *tree = build(arr, n);

    for (int i = 0; i < tree->n; i++) {
        printf("%c : %s\n", tree->codes[i].ch, tree->codes[i].str);
    }
    
    return 0;
}
