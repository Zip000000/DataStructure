/*************************************************************************
	> File Name: 284-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月01日 星期二 21时46分21秒
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
typedef pair<int, int> PII;
set<PII> se;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data[i].p >> data[i].d;
    }
    sort(data, data + n, [](const Data &a, const Data &b) { return a.d < b.d; });

    for (int i = 0; i < n; i++) {
        if (data[i].d > se.size()) {
            se.insert(PII(data[i].p, i));
        } else {
            if (data[i].p < se.begin()->first) continue;
            se.erase(se.begin());
            se.insert(PII(data[i].p, i));
        }
    }
    int ans = 0;
    for (auto iter = se.begin(); iter != se.end(); iter++) {
        ans += iter->first;
    }
    cout << ans << endl;
    
    
    return 0;
}
