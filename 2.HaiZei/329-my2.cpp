/*************************************************************************
	> File Name: 329-my2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月28日 星期三 19时09分41秒
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
#define lowbit(x) ((x) & (-x))
#define MAX_N 100000
int c[MAX_N + 5];

void add(int i, int d, int n) {
    while (i <= n) c[i] += d, i += lowbit(i);
}

int query(int x) {
    int sum = 0;
    while (x > 0) sum += c[x], x -= lowbit(x);
    return sum;
}

int main() {
    int n, now, pre = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> now;
        add(i, now - pre, n);
        pre = now;
    }
    int m;
    char str[10];
    cin >> m;
    int l, r, d, x;
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (str[0] == 'C') {
            cin >> l >> r >> d;
            add(l, d, n);
            add(r + 1, -d, n);
        } else {
            cin >> x;
            cout << query(x) << endl;
        }
    }

    
    
    return 0;
}
