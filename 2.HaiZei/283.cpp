/*************************************************************************
	> File Name: 283.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月21日 星期三 17时34分21秒
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
#define BASE 10
#define MAX_N 100000
#define BASE_LETTER '0'

struct Node {
    int flag;
    int next[BASE];
} Node[MAX_N + 5];

int cnt = 1, root = 1;
inline int getNewNode() { return ++cnt; }

int insert(char *str) {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BASE_LETTER;
        if (Node[p].next[ind] == 0) Node[p].next[ind] = getNewNode();
        Node[p].flag = -1;
        p = Node[p].next[ind];
        if (Node[p].flag == 1) return -1;
    }
    if (Node[p].flag == -1) return -1;
    else Node[p].flag = 1;
    return 0;
}

int main() {
    int n;
    cin >> n;
    int flag = 1;
    for (int i = 0; i < n; i++) {
        char str[MAX_N + 5] = {0};
        cin >> str;
        int ret = insert(str);
        if (ret == -1) flag = 0;
    }
    if (flag == 0) cout  << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
