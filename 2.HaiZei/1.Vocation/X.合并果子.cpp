/*************************************************************************
	> File Name: X.合并果子.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月06日 星期五 19时29分56秒
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

