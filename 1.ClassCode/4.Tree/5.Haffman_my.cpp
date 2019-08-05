/*************************************************************************
	> File Name: 4.Haffman_my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月27日 星期六 12时45分46秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define swap(a, b) { \
    __typeof(a) tmp; \
    tmp = b; \
    b = a; \
    a = tmp; \
}
typedef struct Data {
    char ch;
    double p;
} Data;
Data arr[MAX + 5];

typedef struct Node {
    char ch;
    double p;
    struct Node *next[2];
} Node;

typedef struct HaffmanTree {
    Node *root;
    int n;
} HaffmanTree;
HaffmanTree *getNewTree(int n) {
    HaffmanTree *tree = (HaffmanTree *)malloc(sizeof(HaffmanTree));
    tree->n = n;
    tree->root = NULL;
}
Node *getNewNode(char ch, double p) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->ch = ch;
    n->p = p;
    n->next[0] = n->next[1] = NULL;
    return n;
}
void sortNodes(Node **nodes, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nodes[j]->p > nodes[i]->p) swap(nodes[i], nodes[j]);
        }
    }
}
void print_nodes(Node **nodes, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c[%d]->", nodes[i]->ch, (int)nodes[i]->p);
    }
    printf("\n");
}

HaffmanTree *build(Data *arr, int n) {
    printf("in build\n");
    Node **nodes = (Node **)malloc(sizeof(Node *) * n);

    for (int i = 0; i < n; i++) {
        nodes[i] = getNewNode(arr[i].ch, arr[i].p);    
    }
    sortNodes(nodes, n);
    print_nodes(nodes, n);
    printf("after sort\n");
    
    for (int i = n - 1; i > 0; i--) {
        printf("i = %d in workin:\n", i);
        Node *n = getNewNode(0, nodes[i]->p + nodes[i - 1]->p);
        n->next[1] = nodes[i];
        n->next[0] = nodes[i - 1];
        nodes[i - 1] = n;
        int t = i - 1;
        for (int j = t - 1; j >= 0; j--) {
            if (nodes[t]->p <= nodes[j]->p) break;
            swap(nodes[t], nodes[j]);
            t = j;
        }
        print_nodes(nodes, i);
    }

    HaffmanTree *tree = getNewTree(n);
    tree->root = nodes[0];
    return tree;
}
int s[100], top = 0;
void show_stack(int *stack, int t) {
    for(int i = 0; i < t; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
}
void extractCode(Node *root) {
    if (root == NULL) return;
    if (root->ch != 0) {
        printf("%c : ", root->ch);
        show_stack(s, top);
    }
    s[top++] = 0;
    extractCode(root->next[0]);
    top--;
    s[top++] = 1;
    extractCode(root->next[1]);
    top--;
}
void printf_list(Node *root) {
    if (root == NULL) return;
    printf("%c", root->ch);
    printf("(");
    printf_list(root->next[0]);
    printf(",");
    printf_list(root->next[1]);
    printf(")");

}

int main() {
    int n;
    char str[10];
    scanf("%d", &n);
    for (int i = 0; i <n; i++) {
        scanf("%s %lf", str, &arr[i].p);
        arr[i].ch = str[0];
    }

    HaffmanTree *tree = build(arr, n);
    
    extractCode(tree->root);
    printf("\n");
    printf_list(tree->root);
    printf("\n");
    
    return 0;
}
