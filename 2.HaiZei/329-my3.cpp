/*************************************************************************
	> File Name: 329-my3.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月01日 星期二 16时04分12秒
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
struct TreeArray {
    int c[MAX_N + 5];
    int lowbit(int x) { return x & (-x); }
    void add(int i, int n, int d) {
        while (i <= n) c[i] += d, i += lowbit(i);
    }
    int query(int i) {
        int sum = 0;
        while (i) sum += c[i], i -= lowbit(i);
        return sum;
    }
} ta;

int main() {
    int n;
    cin >> n;
    int tmp, pre = 0;
    //ta.add(0, n, 0);
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        ta.add(i, n, tmp - pre);
        pre = tmp;
    }
    int m; cin >> m;
    char str[10];
    int l, r, d;
    for (int i = 0; i < m; i++) {
        cin >> str;
        switch (str[0]) {
            case 'C': {
                cin >> l >> r >> d;
                ta.add(l, n,  d);
                ta.add(r + 1, n, -d);
            } break;
            case 'Q': {
                cin >> d;
                cout << ta.query(d) << endl;;
            } break;
        }
    }
    
    return 0;
}
