/*************************************************************************
	> File Name: 328-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月02日 星期三 11时19分40秒
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
#define MAX_N 200000
typedef long long ll;
struct TreeArr {
    ll c[MAX_N + 5], n;
    ll lowbit(ll x) { return x & (-x); }
    void add(ll i, ll d) {
        while (i <= n) { c[i] += d; i += lowbit(i); }
    }
    ll query(ll i) {
        ll sum = 0;
        while (i) { sum += c[i]; i -= lowbit(i); }
        return sum;
    }
} ta;

int main() {
    int n;
    cin >> n;
    ta.n = n;
    ll y;
    ll downans = 0, upans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> y;
        ll beforedown = ta.query(y);
        ll afterdown = y - beforedown - 1;
        downans += beforedown * afterdown;

        ll beforeup = i - beforedown - 1;
        ll afterup = (n - y) - beforeup;
        upans += beforeup * afterup;
        ta.add(y, 1);
    }
    cout << upans << " " << downans << endl;
    
    return 0;
}
