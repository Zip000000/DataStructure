/*************************************************************************
	> File Name: 73-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月29日 星期四 19时48分35秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include <unordered_map>
#include<cmath>
using namespace std;
#define MAX_N 1000
#define ind(a, b, m) (((a) * (m)) + (b) + 1)

struct UnionSet {
    int *fa;
    void init(int n) {
        this->fa = new int[n + 5];
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == 0) fa[bb] = aa;
        else fa[aa] = bb;
        /*
        fa[get(a)] = get(b);
        */
    }
};
char g[MAX_N + 5][MAX_N + 5];
int main() {
    int n, m;
    cin >> n >> m;
    UnionSet u;
    u.init(n * m);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++ ) {
            if (g[i][j] != 'O') continue;

            /*
            if (i && j && g[i - 1][j] == 'O') u.merge(ind(i, j, m), ind(i - 1, j, m));
            if (j && i && g[i][j - 1] == 'O') u.merge(ind(i, j, m), ind(i, j - 1, m));
            if (i == 0 || i == n - 1) u.merge(ind(i, j, m), 0);
            if (j == 0 || j == m - 1) u.merge(ind(i, j, m), 0);

            */

            if (i >= 1 && j >= 1) {
                if (g[i][j - 1] == 'O') u.merge(ind(i, j, m), ind(i, j - 1, m));
                if (g[i - 1][j] == 'O') u.merge(ind(i, j, m), ind(i - 1, j, m));
            }
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) u.merge(ind(i, j, m), 0);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != 'O') continue;
            if (u.get(ind(i, j, m)) != u.get(0)) cnt++;
        }
    }
    cout << cnt << endl;
    
    
    return 0;
}
