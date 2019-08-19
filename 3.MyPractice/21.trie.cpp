/*************************************************************************
	> File Name: 21.trie.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月19日 星期一 19时32分23秒
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

#define BASE 26
#define BASE_LETTER 'a'

#define CODE(a) str[i]-'a'
typedef struct Node {
    int flag;
    Node *next[BASE];
} Node;

Node *getNewNode() {
    Node *n = (Node *)calloc(sizeof(Node), 1);
    return n;
}

void insert(Node *root, char *str) {
    if (root == NULL) return;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[CODE(i)] == NULL) p->next[CODE(i)] = getNewNode();
    }
    p->flag = 1;
    return;
}

int query(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        p = p->next[CODE(i)];
        if (p == NULL) return 0;
    }
    return p->flag;
}

int main() {
    
    int n;
    scanf("%d", &n);
    char str[1000];
    Node * root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }

    while (~scanf("%s", str)) {
        printf("find %s ret = %d\n", str, query(root, str));
    }
    
    return 0;
}
