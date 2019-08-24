/*************************************************************************
	> File Name: 325-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月24日 星期六 00时08分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<unordered_map>
using namespace std;

struct UnionSet {
    int *fa, *val;
    void init(int n) {
        this->fa = new int[n + 1];
        this->val = new int[n + 1];
        for (int i = 0; i <= n; i++) fa[i] = i;
        for (int i = 0; i <= n; i++) val[i] = 0;
    }
    int get(int x) {
		if (fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 2;
        return fa[x] = root;
    }
    void merge(int a, int b, int c) { // 0 偶　１　奇
        cout << "merge : " << a << " " << b << " c = " << c << endl; 
        int aa = get(a), bb = get(b);
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 2) % 2;
    }
};

UnionSet u;

int main() {
    int L, Q;
    cin >> L >> Q;
    u.init(2 * Q);
    unordered_map<int, int> hashmap;
    //map<int, int> hashmap;
    int l, r, c, flag = Q;
    char str[10];
    for (int i = 1; i <= Q; i++) {
        scanf("%d %d %s", &l, &r, str);
        if (hashmap.find(l) == hashmap.end()) {
            //cout << "hash[" << l <<"] = " << i << endl; 
            hashmap[l] = i;
        }
        if (hashmap.find(r) == hashmap.end()) hashmap[r] = Q + i;
        int ll = hashmap[l], rr = hashmap[r]; 
        //cout << "ll = " << ll << "l = " << l << "rr = " << rr << "r = " << r << endl;
        if (str[0] == 'e') c = 0; else c = 1;
        if (u.get(ll) == u.get(rr) && abs(u.val[ll] - u.val[rr]) % 2 != c) {
            flag = i - 1; break;
        }
        //if (ll = i) u.merge(ll, rr, c); else u.merge(rr, ll, c);
        u.merge(ll, rr, c);
    }
    cout << flag << endl;
    
    
    return 0;
}
