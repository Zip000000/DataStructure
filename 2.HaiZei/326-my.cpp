/*************************************************************************
	> File Name: 326-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月27日 星期五 13时41分22秒
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
        for (int i = 1; i <= n; i++) fa[i] = i, val[i] = 0;
    }
    int get(int x) {
        if (fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    }
    // 0 同类　　　１　Ｘ吃Ｙ　　２　Ｙ吃Ｘ
    void merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 3) % 3;
        return ;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    int d, x, y;
    UnionSet u;
    u.init(n);
    int ans = 0;
    while (k--) {
        cin >> d >> x >> y;
        if (x > n || y > n) {
            ans += 1;
            //cout << "cnt 1" << endl;
        } else if (u.get(x) == u.get(y) && (u.val[x] - u.val[y] + 3) % 3 != (d - 1)) {
            ans += 1;
        } else {
            u.merge(x, y, d - 1);
        }
    }
    cout << ans << endl;
    
    
    return 0;
}
