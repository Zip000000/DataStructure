/*************************************************************************
	> File Name: 72.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月21日 星期三 20时47分32秒
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

#define MAX_N 10000


//val[i] 记录i节点和父节点的关系 1 2 0
//带权并茶几 的路径压缩
struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i < n; i++) fa[i] = i, val[i] = 0;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
        //return (fa[x] = (x - fa[x] ? get(fa[x]) : x)); 
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

void read(int &n, int &m) {
    cin >> n >> m;
    u.init(n);
    return ;
}

int main() {
    int n, m;
    read(n, m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            u.merge(b, c, 2);
        } else {
            if (u.get(b) != u.get(c)) {
                cout << "Unknown" << endl;
            } else {
                switch ((u.val[b] - u.val[c] + 3) % 3) {
                    case 0: cout << "Tie" << endl; break;
                    case 1: cout << "Loss" << endl; break;
                    case 2: cout << "Win" << endl; break;
                }
            }
        }
    }
    
    
    return 0;
}
