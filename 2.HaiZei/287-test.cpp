/*************************************************************************
	> File Name: 287-test.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月02日 星期三 09时33分44秒
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
typedef pair<int, int> PII;
set<PII> se;

int main() {
    int n, tmp, cnt = 0, ans;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        se.insert(PII(tmp, cnt++));
    }
    while (se.size() > 1) {
        tmp = 0;
        tmp += se.begin()->first;
        se.erase(se.begin());
        tmp += se.begin()->first;
        se.erase(se.begin());

        se.insert(PII(tmp, cnt++));
        ans += tmp;
    }
    cout << ans << endl;
    
    return 0;
}
