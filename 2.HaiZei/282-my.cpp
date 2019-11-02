/*************************************************************************
	> File Name: 282-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月01日 星期二 13时16分44秒
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
#define BASE 2
#define MAX_N 100000

int arr[MAX_N + 5];

struct Node {
    int flag, next[BASE];
} node[(MAX_N << 5) + 5];
int cnt = 2, root = 1;
int getNewNode() { return cnt++; }

void insert(int num) {
    int p = root;
    for (int i = 30; i >= 0; i--) {
        int ind = !!((1 << i) & num);
        if (node[p].next[ind] == 0) node[p].next[ind] = getNewNode();
        p = node[p].next[ind];
    }
    node[p].flag = num;
}

int query(int num) {
    int p = root;
    for (int i = 30; i >= 0; i--) {
        int ind = !!((1 << i) & num);
        int rind = !ind;
        if (node[p].next[rind] == 0) {
            p = node[p].next[ind];
        } else {
            p = node[p].next[rind];
        }
    }
    //cout << " num = " << num << "  " << node[p].flag << endl;
    return num ^ node[p].flag;
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i], insert(arr[i]);
    for (int i = 0; i < n; i++) {
        ans = max(ans, query(arr[i]));
    }
    cout << ans << endl;
    
    return 0;
}
