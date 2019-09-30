/*************************************************************************
	> File Name: 322-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月25日 星期三 18时03分22秒
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
#define MAX_N 1000000
struct UnionSet {
    int *fa;
    void init(int n) {
        fa = new int[n + 1];
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
        return ;
    }
};
struct Data {
    int i, j, e;
} Data[MAX_N + 5];
int cnt;
int main() {
    int t;
    cin >> t;
    map<int, int> ma;
    while (t--) {
        ma.clear();
        cnt = 0;
        int n;
        cin >> n;
        UnionSet u;
        u.init(n);
        for (int i = 0; i < n; i++) {
            cin >> Data[i].i >> Data[i].j >> Data[i].e;
            
        }
        for (int k = 0; k < n; k++) {
            int i = Data[k].i, j = Data[k].j, e = Data[k].e;
            if (e == 0) continue;
            if (ma.find(i) == ma.end()) ma[i] = (++cnt);
            if (ma.find(j) == ma.end()) ma[j] = (++cnt);
            u.merge(ma[i], ma[j]);
        }
        int flag = 1;
        for (int k = 0; k < n; k++) {
            int i = Data[k].i, j = Data[k].j, e = Data[k].e;
            if (e == 1) continue;
            if (ma.find(i) == ma.end() || ma.find(j) == ma.end()) continue;
            if (u.get(ma[i]) != u.get(ma[j])) continue;
            flag = 0;
            break;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    
    
    
    return 0;
}
