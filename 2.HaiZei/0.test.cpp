/*************************************************************************
	> File Name: 324.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月22日 星期四 18时49分47秒
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

#define MAX_N 500000

struct UnionSet {
    int fa[MAX_N + 5], size[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i, size[i] = 1, val[i] = 0;
    }

    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        cout << "in get : " << "val[" << x << "] = " << val[x] << " ; val[" << fa[x] << "]";
        cout << " = " << val[fa[x]] << endl;
        val[x] += val[fa[x]];
        return fa[x] = root;
    } 
//a 所在集合 做儿子
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return;
        fa[aa] = bb;
        val[aa] = size[bb];
        size[bb] += size[aa];
        return ;
    }
};

UnionSet u;

int main() {
    u.init(10);
    for (int i = 1; i < 9; i++) {
        u.merge(1, i + 1);
        cout << "merge " << 1 << " and " << i << endl;
    }

    for (int i = 1; i < 10; i++) {
        cout << " size : " << u.size[i] << " val : " <<  u.val[i] << endl;
    }
    
    for (int i = 0 ; i < 10; i++) {
        cout << u.get(1) << endl;
    }
    return 0;
}
