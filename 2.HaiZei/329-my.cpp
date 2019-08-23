/*************************************************************************
	> File Name: 329-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月23日 星期五 00时47分17秒
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

#define MAX_N 100000
int num[MAX_N + 5];

int c[MAX_N + 5];

inline int lowbit(int x) { return x & (-x); }

void add(int i, int val, int n) {
    while (i <= n) c[i] += val, i += lowbit(i);
}

int query(int i, int n) {
    int sum = 0;
    while (i > 0) sum += c[i], i -= lowbit(i);
    return sum;
}

int main() {
    int n;
    cin >> n;
    int now = 0, pre = 0;
    for (int i = 1; i <= n; i++) {
        cin >> now;
        add(i, now - pre, n);
        pre = now;
    }
    int m;
    cin >> m;
    char str[10];
    for (int i = 0; i < m; i++) {
        cin >> str;
        switch (str[0]) {
            case 'C' : {
                int l, r, d;
                cin >> l >> r >> d;
                add(l, d, n);
                add(r + 1, -d, n);
            } break;
            case 'Q' : {
                int x;
                cin >> x;
                cout << query(x, n) << endl;
            } break;
        }
    }
    
    return 0;
}
