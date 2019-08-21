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

void insert(int n) {
    int p = root;
    for (int i = BASE; i >= 0; --i) {
        int ind = !!((1 << i) & n);
        if (Node[p].next[ind] == 0) Node[p].next[ind] = getNewNode();
        p = Node[p].next[ind];
    }
    Node[p].num = n;
    return;
}

int query(int n) {
    int rp = root;
    for (int i = BASE; i >= 0; --i) {
        int ind = !!((1 << i));
        int rnxt = Node[rp].next[!ind];
        int nxt = Node[rp].next[ind];
        if (rnxt == 0) rp = rnxt; else rp = nxt;
    }
    return n ^ Node[rp].num;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i], insert(arr[i]);
    int max = 0;
    for (int i = 0; i < n; i++) {
        int tmp = query(arr[i]);
        if (tmp > max) max = tmp;
    }
    cout << max << endl;
    return 0;
}
