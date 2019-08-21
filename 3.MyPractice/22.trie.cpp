/*************************************************************************
	> File Name: 22.trie.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月20日 星期二 13时15分43秒
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

#define CODE(i) (str[i] - BASE_LETTER)

typedef struct Node {
    int flag;
    Node *next[BASE];
} Node;

Node *getNewNode() {
    Node *n = (Node *)calloc(sizeof(Node), 1);
    return n;
}

void insert(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[CODE(i)] == NULL) p->next[CODE(i)] = getNewNode();
        p = p->next[CODE(i)];
    }
    p->flag = 1;
    return ;
}

int query(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p == NULL) return 0;
        p = p->next[CODE(i)];
    }
    return p->flag;
}

void output(Node *root, int k, char *buff) {
    if (root == NULL) return;
    if (root->flag == 1) cout << buff << endl;
    
    for (int i = 0; i < BASE; i++) {
        buff[k] = i + BASE_LETTER;
        buff[k + 1] = '\0';
        output(root->next[i], k + 1, buff);
    }
}


void clear(Node *root) {
    if (root == NULL) return;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int main() {
    char str[1000]; 
    int n;
    cin >> n;
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    cout << "---------------------------------" << endl;
    output(root, 0, str);
    cout << "---------------------------------" << endl;
    while (~scanf("%s", str)) {
        printf("query %s ret = %s\n", str, query(root, str) ? "YES" : "NO");
    }


    return 0;
}
