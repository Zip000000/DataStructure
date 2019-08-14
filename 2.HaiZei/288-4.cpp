/*************************************************************************
	> File Name: 287.Haizei.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月12日 星期一 19时10分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <queue>
using namespace std;

priority_queue <int, vector<int> > p;
priority_queue <int, vector<int>, greater<int> > q;
#define MAX 30000
int main() {
    int n, m;
    cin >> n >> m;
    int num[MAX + 5], op[MAX+5];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int cnt = 0;
    for (int j = 0; j < m; j++) {
        cin >> op[j];
        while (p.size() < op[j]) {
            if (p.size() == 0 || num[cnt] < p.top()) p.push(num[cnt++]);
            else q.push(num[cnt++]);
        }
        while (p.size() > j + 1) {
            q.push(p.top());
            p.pop();
        }
        while (p.size() < j + 1) {
            p.push(q.top());
            q.pop();
        }
        cout << p.top()<< endl;;
    }

    return 0;
}
