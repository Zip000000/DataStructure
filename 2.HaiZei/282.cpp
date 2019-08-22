/*************************************************************************
	> File Name: 282.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月21日 星期三 16时38分49秒
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

#define MAX_N 3200000
#define BASE 30
struct Node {
    int num;
    int next[2];
} Node[MAX_N + 5];

int cnt = 1, root = 1;
int arr[(MAX_N >> 5) + 5];
inline int getNewNode() { return ++cnt; }

void insert(int num) {
    int p = root;
    for (int i = BASE; i >= 0; i--) {
        int ind = !!((1 << i) & num);
        if (Node[p].next[ind] == 0) Node[p].next[ind] = getNewNode();
        p = Node[p].next[ind];
    }
    Node[p].num = num;
    return;
}

int query(int num) {
    int p = root;
    for (int i = BASE; i >= 0; i--) {
        int ind = !!((1 << i) & num);
        int rind = !ind;
        if (Node[p].next[rind]) p = Node[p].next[rind];
        else p = Node[p].next[ind];
    }
    return num ^ Node[p].num;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i], insert(arr[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, query(arr[i]));
    }
    cout << ans << endl;
    return 0;
}

        /*
        int rnxt = Node[rp].next[!ind];
        int nxt = Node[rp].next[ind];
        if (nxt == 0) rp = rnxt; else rp = nxt;
        */
