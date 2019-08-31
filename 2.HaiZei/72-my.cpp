/*************************************************************************
	> File Name: 73-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月29日 星期四 18时50分27秒
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
        this->fa = new int[n + 5];
        this->val = new int[n + 5];
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;
        }
    }
    int get(int x) {
        if (fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] = (val[x] + val[fa[x]]) % 3;
        fa[x] = root;
        return root;
    }
    void merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (val[b] + c - val[a] + 3) % 3;
        return ;
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
                //a, b   :  1(a > b)  0(a == b) 2(a < b)
                u.merge(b, c, 1);
            } break;
            case 2: {
                if (u.get(b) != u.get(c)) {
                    cout << "Unknown" << endl;
                    break;
                }
                int ind = (u.val[b] - u.val[c] + 3) % 3;
                switch (ind) {
                    case 0: cout << "Tie" << endl; break;
                    case 1: cout << "Win" << endl; break;
                    case 2: cout << "Loss" << endl; break;
                }
            } break;
        }
    }
    
    
    
    return 0;
}
