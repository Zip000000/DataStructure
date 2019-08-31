/*************************************************************************
	> File Name: 71-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月29日 星期四 18时40分10秒
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

struct UnionSet {
    int *fa;
    void init(int n) {
        this->fa = new int[n + 5];
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }

    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    UnionSet u;
    u.init(n);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        switch (a) {
            case 1: {
                u.merge(b, c);
            } break;
            case 2: {
                cout << (u.get(b) == u.get(c) ? "Yes" : "No") << endl;
            } break;
        }
    }
    
    return 0;
}
