/*************************************************************************
	> File Name: V.拨号.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月06日 星期五 19时46分41秒
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

#define MAX_N 100000
#define BASE 10
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
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - '0';
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
        p->flag += 1;
    }
    p->flag -= 1;
    if (p->flag != 0) return -1;
    else return 0;
}

char str[MAX_N + 5];
int main() {
    int n;
    Node *root = getNewNode();
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (insert(root, str) == -1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    
    return 0;
}
