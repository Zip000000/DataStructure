/*************************************************************************
	> File Name: 00.test.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月19日 星期一 10时22分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

typedef struct DATrie {
    int *base, *check;
    int root, size;
} DATrie;

DATrie *getDATrie(int n) {
    DATrie *t = (DATrie *)malloc(sizeof(DATrie));
    t->base = (int *)calloc(n, sizeof(int));
    t->check = (int *)calloc(n, sizeof(int));
    t->root = 1;
    t->size = n;
    t->check[t->root] = -1;
    return t;
}

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    return p;
}

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) cnt++, p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int getBaseValue(Node *root, DATrie *tree) {
    int base = 1;
    while (1) {
        base += 1;
        int flag = 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (tree->check[base + i] == 0) continue;
            flag = 0;
            break;
        }
        if (flag) break;
    }
    return base;
}

void buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue(root, tree);
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int child = base + i;
        tree->check[child] = (root->next[i]->flag ? -ind : ind);
    }

    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int child = base + i;
        buildDATrie(child, root->next[i], tree);
    }
    return ;
}

int query(DATrie *tree, const char *str) {
    int p = tree->root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        int child = tree->base[p] + ind;
        if (abs(tree->check[child]) != p) return false;
        p = child;
    }
    return (tree->check[p] < 0);
}

void clearDA(DATrie *tree) {
    if (tree == NULL) return ;
    free(tree->base);
    free(tree->check);
    free(tree);
    return ;
}

int main() {
    int n, cnt1 = 1, cnt2;
    char str[100];
    scanf("%d", &n);
    Node *root = getNewNode();
    while (n--) {
        scanf("%s", str);
        cnt1 += insert(root, str);
    }
    DATrie *tree = getDATrie(cnt1 * BASE + 5);
    buildDATrie(tree->root, root, tree);
    while (~scanf("%s", str)) {
        printf("search %s, result = %s\n", str, query(tree, str) ? "YES" : "NO");
    }
    /*
    int mem1 = cnt1 * sizeof(Node), mem2 = cnt2 * sizeof(int) * 2 + sizeof(int) * 2;
    printf("Trie memory : %d Bytes\n", mem1);
    printf("Double Array Trie memory : %d Bytes\n", mem2);
    printf("memory rate : %.4lf%%\n", 1.0 * mem2 / mem1 * 100);
    */
    clearDA(tree);
    clear(root);
    return 0;
}
