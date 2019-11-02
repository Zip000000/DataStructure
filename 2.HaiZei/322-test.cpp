/*************************************************************************
	> File Name: 322-test.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月02日 星期三 09时40分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <unordered_map>
using namespace std;
#define MAX_N 1000000
struct Data {
    int i, j, e;
} d[MAX_N + 5];
struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) { 
        for (int i = 1; i <= n; i++) fa[i] = i; 
    }
    int get(int x) { return fa[x] = (fa[x] == x ? x : get(fa[x]));}
    void merge(int a, int b) { fa[get(a)] = get(b); }
};

unordered_map<int, int> ma;
void solve() {
    int n, i, j, e, cnt = 0;
    cin >> n;
    UnionSet u;
    u.init(n);
    ma.clear();
    for (int i = 0; i < n; i++) {
        cin >> d[i].i >> d[i].j >>d[i].e;

    }
    for (int i = 0; i < n; i++) {
        int ii = d[i].i, jj = d[i].j, ee = d[i].e;
        if (ee == 0) continue;
        if (ma.find(ii) == ma.end()) ma[ii] = ++cnt;
        if (ma.find(jj) == ma.end()) ma[jj] = ++cnt;
        u.merge(ii, jj);
    }

    for (int i = 0; i < n; i++) {
        int ii = d[i].i, jj = d[i].j, ee = d[i].e;
        if (ee == 1) continue;
        if (ma.find(ii) == ma.end() || ma.find(jj) == ma.end()) continue;
        if (u.get(ma[ii]) != u.get(ma[jj])) continue;
        cout << "NO" << endl;
        return ;
    }
    cout << "YES" << endl;
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
