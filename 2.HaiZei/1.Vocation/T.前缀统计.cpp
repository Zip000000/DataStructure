/*************************************************************************
	> File Name: T.前缀统计.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月06日 星期五 21时46分34秒
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
#define MAX_N 1000000
char str[MAX_N + 5];
typedef struct Node {
    int flag;
    Node *next[BASE];
} Node;

Node *getNewNode() {
    Node *n = (Node *)calloc(sizeof(Node), 1);
    return n;
}

int insert(Node *root, const char *str) {
    Node *p = root;
    int ret = 0;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BASE_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
        ret += p->flag;
    }
    p->flag += 1;
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    Node *root = getNewNode();

    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }

    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        printf("%d\n", insert(root, str));
    }
    
    
    return 0;
}
