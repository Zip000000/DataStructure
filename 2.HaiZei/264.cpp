/*************************************************************************
	> File Name: 264.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月27日 星期五 17时20分04秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <stack>
using namespace std;
#define MAX_N 100000
long long arr[MAX_N + 5], l[MAX_N + 5], r[MAX_N + 5];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    stack<int> stk;
    stk.push(0);
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
        l[i] = i - stk.top();
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    stk.push(0);
    for (int i = n; i >= 1; --i) {
        while (!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
        r[i] = stk.top() - i;
        stk.push(i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long ind = arr[i] * (l[i] + r[i] - 1);
        ans = (ans > ind ? ans : ind);
    }
    cout << ans << endl;
    
    return 0;
}
