/*************************************************************************
	> File Name: 326.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月22日 星期四 15时13分57秒
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

#define MAX_N 50000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; i++) fa[i] = i, val[i] = 0;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    }
    void merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return;
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 3) % 3;
        return ;
    }
};

UnionSet u;

int main() {
    int n, k;
    cin >> n >> k;
    int d, x, y;
    int cnt = 0;
    u.init(n + 5);
    for (int i = 0; i < k; i++) {
        cin >> d >> x >> y;   
        if (x > n || y > n) { cnt++; continue; }
        if (u.get(x) == u.get(y) && d - 1 != (u.val[x] - u.val[y] + 3) % 3) {
            cnt++; continue; 
        }
        u.merge(x, y, d - 1);
    }
    cout << cnt << endl;
    
    return 0;
}
