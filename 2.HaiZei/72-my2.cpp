/*************************************************************************
	> File Name: 72-my2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月23日 星期一 16时12分55秒
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
    int *fa, *val;
    void init(int n) {
        this->fa = new int[n + 1];
        this->val = new int[n + 1];
        for (int i = 1; i <= n; i++) fa[i] = i, val[i] = 0;
    }
    int get(int x) {
        if (fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    }
    void merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 3) % 3;
        return ;
    }
};

UnionSet u;
int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    int a, b, c;
    char str[][100] = {"Tie", "Win", "Loss", "Unknown"};
    while (m--) {
        cin >> a >> b >> c;
        switch (a) {
            case 1: {
                u.merge(b, c, 1);
            } break;
            case 2: {
                int ind = 0;
                //cout << "u.get(b) = " << u.get(b) << "   :   " << u.get(c) << endl;
                if (u.get(b) != u.get(c)) {
                    ind = 3;
                } else {
                    ind = (u.val[c] - u.val[b] + 3 ) % 3;
                } 
                cout << str[ind] << endl;
            } break;
        }
    }
    return 0;
}
