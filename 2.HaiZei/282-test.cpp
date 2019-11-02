/*************************************************************************
	> File Name: 282-test.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月02日 星期三 09时13分06秒
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
#define BASE 2
int arr[MAX_N + 5];
struct Node {
    int num, next[BASE];
} node[(MAX_N << 5) + 5];
int root = 1, cnt = 1;
int getNewNode() { return ++cnt; }
void insert(int num) {
    int p = root;
    for (int i = 30; i >= 0; i--) {
        int ind = !!(num & (1 << i));
        if (node[p].next[ind] == 0) node[p].next[ind] = getNewNode();
        p = node[p].next[ind];
    }
    node[p].num = num;
}

int query(int num) {
    int p = root, q = root;
    for(int i = 30; i >= 0; i--) {
        int ind = !!(num & (1 << i));
        int rind = !ind;
        p = node[p].next[ind];
        if (node[q].next[rind] != 0) q = node[q].next[rind];
        else q = node[q].next[ind];
    }
    return node[q].num ^ num;
}

int main() {
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        insert(arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, query(arr[i]));
    }
    cout << ans << endl;
    
    return 0;
}
