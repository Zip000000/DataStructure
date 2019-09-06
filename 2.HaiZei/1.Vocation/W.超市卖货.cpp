/*************************************************************************
	> File Name: W.超市卖货.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月06日 星期五 18时26分21秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <set>
using namespace std;

#define MAX_N 10000

struct Data {
    int d, p;
} data[MAX_N + 5];

bool cmp(const struct Data &a, const struct Data &b) {
    return a.d < b.d;
}

typedef pair<int, int> PII;
set<PII> s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data[i].p >> data[i].d;
    }
    sort(data, data + n, cmp);
    
    for (int i = 0; i < n; i++) {
        if (data[i].d > s.size()) {
            s.insert(PII(data[i].p, i));
        } else if (data[i].p > s.begin()->first) {
            s.erase(s.begin());
            s.insert(PII(data[i].p, i));
        }
    }
    int ans = 0;
    for (auto it = s.begin(); it != s.end(); it++) ans += it->first;
    cout << ans << endl;
    return 0;
}
