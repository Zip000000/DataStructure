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

int main() {
    int n, m;
    cin >> n >> m;
    int *num = (int *)malloc(sizeof(int) * (n + 5));
    int *op = (int *)malloc(sizeof(int) * (m + 5));

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> op[j];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        q.push(num[i]);
        while (i == op[cnt]) {
            cnt++;
            while (p.size() <= cnt) {
                p.push(q.top());
                q.pop();
            }
            cout << p.top() << endl;
        }
    }

    return 0;
}
