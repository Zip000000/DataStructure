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

priority_queue <int, vector<int>, greater<int> > q;

int main() {
    int n, a, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a, q.push(a);

    for (int i = 1; i < n; i++) {
        int val1 = q.top(); q.pop();
        int val2 = q.top(); q.pop();
        q.push(val1 + val2);
        sum += val1 + val2;
    }
    cout << sum << endl;
    return 0;
}
