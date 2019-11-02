/*************************************************************************
	> File Name: 281-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月01日 星期二 13时01分44秒
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
#define BASELETTER 'a'
#define MAX_N 1000000
struct Node {
    int flag;
    int next[BASE];
} node[MAX_N + 5];
int cnt = 1, root = 0;
int getNewNode() { return cnt++; }

void add_str(string str) {
    int p = root;
    for (char it : str) {
        int ind = it - BASELETTER;
        if (node[p].next[ind] == 0) node[p].next[ind] = getNewNode();
        p = node[p].next[ind];
    }
    node[p].flag += 1;
    return ;
}
int query(string str) {
    int p = root;
    int ret = 0;
    for (char it : str) {
        int ind = it - BASELETTER;
        ret += node[p].flag;
        if (node[p].next[ind] == 0) return ret;
        p = node[p].next[ind];
    }
    ret += node[p].flag;
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        add_str(str);
    }

    for (int i = 0; i < m; i++) {
        cin >> str;
        cout << query(str) << endl;;
    }
    
    
    return 0;
}
