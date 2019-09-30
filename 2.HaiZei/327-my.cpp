/*************************************************************************
	> File Name: 327-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月27日 星期五 14时16分46秒
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
#define MAX_M 20000
typedef struct Data {
    int a, b, c;
} Data;
Data arr[MAX_N + 5];

struct UnionSet {
    int fa[MAX_M + 5], val[MAX_M + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i, val[i] = 0;
        return ;
    }
    int get(int x) {
        if (fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 2;
        return fa[x] = root;
    }
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (1 + val[b] - val[a] + 2) % 2;
        return ;
    }
};

bool cmp(const Data &a, const Data &b) {
    return a.c > b.c;
}

UnionSet u;
int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }
    sort(arr, arr + m, cmp);
    u.init(n);
    int flag = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int a = arr[i].a, b = arr[i].b, c = arr[i].c;
        if (u.get(a) == u.get(b) && abs(u.val[a] - u.val[b]) == 0) {
            ans  = c;
            break;
        }
        u.merge(a, b);
    }
    cout << ans << endl;
    
    
    return 0;
}
