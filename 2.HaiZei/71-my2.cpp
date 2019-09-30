/*************************************************************************
	> File Name: 71-my2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月23日 星期一 16时06分36秒
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
        this->fa = new int[n + 1];
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
UnionSet u;
int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    int a, b, c;
    while (m--) {
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
