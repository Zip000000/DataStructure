/*************************************************************************
	> File Name: Z.程序自动分析.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月05日 星期四 10时43分42秒
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
#define MAX_N 1000000

struct UnionSet {
    int *fa, *val;
    void init(int n) {
        this->fa= new int[n + 5];
        this->val = new int[n + 5];
        for (int i = 1; i <= n; i++) fa[i] = i, val[i] = 0;
    }

    int get(int x) {
        if (fa[x] == x) return x;
        int root  = get(fa[x]);
        val[x] = (val[x] + val[fa[x]]) % 2;
        fa[x] = root;
        return root;
    }
    
    void merge(int a, int b, int v) {
        int aa = get(a), bb = get(b);

        if (aa == bb) return;
        fa[aa] = bb;
        val[aa] = (v + val[b] - val[a] + 2) % 2;
        fa[aa] = bb;
        return ;
    }

};

int cnt = 1;
int main() {
    unordered_map<int, int> hash_map;
    UnionSet u;
    u.init(MAX_N);
    int t;
    cin >> t;
    for (int i1 = 0; i1 < t; i1++) {
        int n;
        cin >> n;
        int flag = 1;
        for (int j1 = 0; j1 < n; j1++) {
            int i, j, e;
            cin >> i >> j >> e;
            
            if (hash_map.find(i) == hash_map.end()) {
                hash_map[i] = cnt++;
            }
            if (hash_map.find(j) == hash_map.end()) {
                hash_map[j] = cnt++;
            }
            i = hash_map[i];
            j = hash_map[j];

            //0 ==    ;   1 !=
            if (e == 1) {
                if (u.get(i) == u.get(j) && abs(u.val[i] - u.val[j]) % 2 == 1) {
                    flag = 0;
                } else {
                    u.merge(i, j, 0);
                }
            } else {
                if (u.get(i) == u.get(j) && abs(u.val[i] - u.val[j]) % 2 == 0) {
                    flag = 0;
                } else {
                    u.merge(i, j, 1);
                }
            }
        }
        cout << (flag == 0 ? "NO" : "YES") << endl;
    }
    
    
    return 0;
}
