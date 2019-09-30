/*************************************************************************
	> File Name: 324-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月27日 星期五 13时18分05秒
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
        for (int i = 1; i <= n; i++) {
            fa[i] = i, val[i] = 0, size[i] = 1;
        }
        return ;
    }
    int get(int x) {
        if (fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        return fa[x] = root;
    }

    //a is son
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        fa[aa] = bb;
        val[aa] += size[bb];
        size[bb] += size[aa];
        return ;
    }
};

int main() {
    int n;
    cin >> n;
    char str[10];
    int i, j;
    UnionSet u;
    u.init(n);
    while (n--) {
        scanf("%s %d %d", str, &i, &j);
        switch(str[0]) {
            case 'M': {
                u.merge(i, j);
            } break;
            case 'C': {
                if (u.get(i) != u.get(j)) {
                    printf("-1\n");
                } else {
                    printf("%d\n", abs(u.val[i] - u.val[j]) - 1);
                }
            } break;
        }
    }
    
    
    return 0;
}
