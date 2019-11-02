/*************************************************************************
	> File Name: 288-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月01日 星期二 22时41分52秒
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
struct classCmp {
    bool operator()(const PII &a, const PII &b) { 
        return a.first > b.first;    
    }
};
set<PII> se2;
set<PII, classCmp> se1;
#define MAX_N 30000
int arr[MAX_N + 5], query[MAX_N + 5];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> query[i];
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (; cnt < query[i]; cnt++) {
            if (se1.empty() || arr[cnt] >= se1.begin()->first) {
                se2.insert(PII(arr[cnt], cnt));
            } else {
                se2.insert(*se1.begin());
                se1.erase(se1.begin());
                se1.insert(PII(arr[cnt], cnt));
            }
        }
        cout << se2.begin()->first << endl;
        se1.insert(*se2.begin());
        se2.erase(se2.begin());
    }
    return 0;
}
