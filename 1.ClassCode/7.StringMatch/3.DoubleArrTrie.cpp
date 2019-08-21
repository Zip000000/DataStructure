/*************************************************************************
	> File Name: 3.DoubleArrTrie.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月21日 星期三 14时14分38秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

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

int cnt = 1;

DATrie *getDATrie(int n) {
    DATrie *trie = (DATrie *)calloc(sizeof(DATrie), 1);
    trie->root = 1;
    trie->size = n;
    trie->base = (int *)calloc(sizeof(int), n);
    trie->check = (int *)calloc(sizeof(int), n);
    trie->check[trie->root] = -1;
    return trie;
}

Node *getNewNode() {
    cnt++;
    Node *n = (Node *)calloc(sizeof(Node), 1);
    return n;
}

void insert(Node *root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return ;
}

int getBaseValue(Node *root, DATrie *trie) {
    int base = 1, flag;
    do {
        flag = 1;
        base += 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (trie->check[base + i] == 0) continue;
            flag = 0;
            break;
        }
    } while (!flag);
    return base;
}

void build_DATrie(int ind, Node *root, DATrie *trie) {
    int b = trie->base[ind] = getBaseValue(root, trie);
    
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        //trie->check[b + i] = ind;
        trie->check[b + i] = ind * (root->next[i]->flag ? -1 : 1);
    }

    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        build_DATrie(b + i, root->next[i], trie);
    }
    //if (root->flag) trie->check[ind] = -trie->check[ind];
    return ;
}

void clear(Node *root) {
    if (root == NULL) return;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

void clearDA(DATrie *trie) {
    if (trie == NULL) return;
    free(trie->base);
    free(trie->check);
    free(trie);
}

int query(DATrie *trie, const char *str) {
    int p = trie->root;
    for (int i  = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (abs(trie->check[trie->base[p] + ind]) != p) return 0;
        p = trie->base[p] + ind;
    }
    return trie->check[p] < 0;
}


int main() {
    int n;
    scanf("%d", &n);
    char str[128];
    Node *root = getNewNode();
    while (n--) {
        scanf("%s", str);

        printf("befor insert\n");
        insert(root, str);
        printf("after insert\n");
    }
    printf("Befor getDATrie\n");
    DATrie *trie = getDATrie(cnt * BASE + 100);
    printf("After getDATrie\n");
    
    printf("Befor build\n");
    build_DATrie(trie->root, root, trie);
    printf("after build\n");
    
    while (~scanf("%s", str)) {
        printf("search %s , ret = %s\n", str, query(trie, str) ? "YES" : "NO");
    }
    clearDA(trie);
    clear(root);
    
    return 0;
}
