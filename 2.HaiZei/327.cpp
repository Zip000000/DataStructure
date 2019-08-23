/*************************************************************************
	> File Name: 327.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月23日 星期五 13时28分09秒
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

#define MAX_N 20000
#define MAX_M 100000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; i++) fa[i] = i, val[i] = 0;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 2;
        return fa[x] = root;
    }
    void merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return;
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 2) % 2;
        //val[aa] = (val[bb] + 1) % 2;
        return ;
    }
};

UnionSet u;

struct Data {
    int a, b, c;
} data[MAX_M + 5];

bool cmp(const Data &a, const Data &b) {
    return a.c > b.c;
}

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    for (int i = 0; i < m; i++) {
        cin >> data[i].a >> data[i].b >> data[i].c;
    }
    sort(data, data + m, cmp);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int a = data[i].a, b = data[i].b;
        if (u.get(a) == u.get(b) && abs(u.val[a] - u.val[b]) == 0) {
            ans = data[i].c;
            break;
        }
        u.merge(a, b, 1);
    }
    cout << ans << endl;

    return 0;
}
