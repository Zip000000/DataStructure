/*************************************************************************
	> File Name: 2.Haffman.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月21日 星期日 20时30分56秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 1000
#define swap(a, b) { \
    __typeof(a) temp = a; \
    a = b, b = temp; \
}

typedef struct Node {
    char ch;
    double p;
    struct Node *next[2];
} Node;

typedef struct Code {
    char ch;
    char *str;
} Code;

typedef struct HaffmanTree {
    Node *root;
    int n; //多少种字符
    Code *codes;
} HaffmanTree;

typedef struct Data {
    char ch;
    double p;
} Data;
Data arr[MAX_N + 5];
HaffmanTree *getNewTree(int n) {
    HaffmanTree *tree = (HaffmanTree *)malloc(sizeof(HaffmanTree));
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    tree->root = NULL;
    tree->n = n;

    return tree;
}
Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = (obj ? obj->ch : 0);
    p->p = (obj ? obj->p : 0);
    p->next[0] = p->next[1] = NULL;
    return p;
}
void insert_once(Node **arr, int n) {
    for (int j = n; j >= 1; j--) {
        if (arr[j]->p > arr[j - 1]->p) {
            swap(arr[j], arr[j - 1]);
            continue;
        }
        break;
    }
}

int extractCodes(Node *root, Code *arr, int k, int l,char *buff) {
    if (root->next[0] == NULL && root->next[1] == NULL) {
        arr[k].ch = root->ch;
        arr[k].str = strdup(buff); //将buff完整的copy一份
        return 1;
    }
    int delta = 0;
    buff[l] = '0';
    delta += extractCodes(root->next[0], arr, k + delta, l + 1, buff);
    buff[l] = '1';
    delta += extractCodes(root->next[1], arr, k + delta, l + 1, buff);
    return delta;
}

HaffmanTree *build(Data *arr, int n) {
    Node **nodes = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) {
        nodes[i] = getNewNode(arr + i);
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j >= 1; j--) {
            if (arr[j].p > arr[j - 1].p) swap(arr[j], arr[j - 1]);
            break;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        Node *p = getNewNode(NULL);
        p->next[0] = nodes[i];
        p->next[1] = nodes[i - 1];
        p->p = p->next[0]->p + p->next[1]->p;
        nodes[i - 1] = p;
        insert_once(nodes, i - 1);
    }
    /*
    for(int i = 0; i < n; i++) {
        printf("%c ", nodes[i]->ch);
    }
    */
    char *buff = (char *)malloc(sizeof(char) * n);
    HaffmanTree *tree = getNewTree(n);
    tree->root = nodes[0];
    extractCodes(tree->root, tree->codes, 0, 0, buff);
    free(nodes);
    free(buff);
}



int main() {
    int n;
    char str[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %lf", str, &arr[i].p);
        arr[i].ch = str[0];
    }
    HaffmanTree *tree = build(arr, n);    
    for (int i = 0; i < tree->n; i++) {
        printf("%c %s\n", tree->codes[i].ch, tree->codes[i].str);
    }
    return 0;
}
