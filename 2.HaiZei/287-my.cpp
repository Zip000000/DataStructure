/*************************************************************************
	> File Name: 287-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月01日 星期二 22时20分00秒
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
int arr[MAX_N + 5];
typedef pair<int, int > PII;
set<PII> se;
int cnt = 0;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        se.insert(PII(tmp, cnt++));    
    }
    int ans = 0;
    while (se.size() > 1) {
        int tmp = 0;
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
