/*************************************************************************
	> File Name: 243.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月01日 星期二 09时17分52秒
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
ll s[MAX_N + 5], e[MAX_N + 5], d[MAX_N + 5];
ll n;
ll get_ind(ll x) {
    ll ret = 0;
    for (ll i = 1; i <= n; i++) {
        ll minr = (x < e[i] ? x : e[i]);
        if (s[i] > x) continue;
        ret += ((minr - s[i]) / d[i] + 1);
    }
    return ret;
}

void binary_search(ll l, ll r) {
    ll mid;
    while (l < r) {
        mid = (l + r) >> 1;
        ll ind = get_ind(mid);
        if (ind & 1) r = mid;
        else l = mid + 1;
    }
    ll ind1 = get_ind(l);
    ll ind2 = 0;
    if (l - 1 >= 1) ind2 = get_ind(l - 1);
    if (l == r  && (ind1 & 1)) {
        cout << l << " " << ind1 - ind2 << endl;
    } else {
        cout << "Poor QIN Teng:(" <<endl;
    }
    return ;
}

void solve() {
    cin >> n;
    ll maxe = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> s[i] >> e[i] >> d[i];
        maxe = max(maxe, e[i]);
    }
    binary_search(1, maxe);
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
