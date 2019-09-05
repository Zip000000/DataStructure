/*************************************************************************
	> File Name: Z2.银河英雄传说.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月05日 星期四 12时47分17秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <unordered_map>
using namespace std;
#define MAX_N 500000

struct UnionSet {
    int *fa, *val, *size;
    void init(int n) {
        this->fa= new int[n + 5];
        this->val = new int[n + 5];
        this->size = new int[n + 5];
        for (int i = 1; i <= n; i++) fa[i] = i, val[i] = 1, size[i] = 1;
    }

    int get(int x) {
        if (fa[x] == x) return x;
        int root  = get(fa[x]);

        fa[x] = root;
        return root;
    }
    
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);

        if (aa == bb) return;
        fa[aa] = bb;
        val[aa] = (v + val[b] - val[a] + 2) % 2;
        fa[aa] = bb;
        return ;
    }

};

int main() {
    UnionSet u;
    u.init(MAX_N);

    int n;
    cin >> n;
    char str[10];
    int a, b;
    for (int i= 0; i > n; i++) {
        scanf("%s %d %d", str, &a, &b);
        switch (str[0]) {
            case 'M': {
                u.merge(a, b);
            } break;
            case 'C': {
                if (u.get(a) != u.get(b)) {
                    printf("-1\n");
                } else {
                    printf("%d\n", abs(u.val[a] - u.val[b]));
                }
            } break;
        }
    }
    
        
    return 0;
}
