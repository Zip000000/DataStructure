/*************************************************************************
	> File Name: 01.tree_thread.c
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月05日 星期一 14时38分10秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int keey, ltag, rtag;
    struct Node *lc, *rc;
} Node;

Node *init(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
}

int main() {
    int n;
    Node *root = NULL;
    while (scanf("%d", &n) != EOF) {
        root = insert(root, n);
    }
    build(root);
    output_thread(root);
    output(root);
    clear(root);



    return 0;
}
