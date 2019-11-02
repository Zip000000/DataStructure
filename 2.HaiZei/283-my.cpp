/*************************************************************************
	> File Name: 283-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月28日 星期六 14时00分13秒
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
struct Node {
    int flag, next[BASE];
} node[MAX_N + 5];
int cnt = 2, root = 1;
int getNewNode() { return cnt++; }
int insert(string &str) {
    int p = root;
    for (auto it : str) {
        int ind = it - '0';
        if (node[p].next[ind] == 0) node[p].next[ind] = getNewNode();
        if (node[p].flag == -1) return -1;
        node[p].flag += 1;
        p = node[p].next[ind];
    }
    if (node[p].flag != 0) return -1;
    node[p].flag = -1;
    return 0;
}

int main() {
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (insert(str) == -1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
