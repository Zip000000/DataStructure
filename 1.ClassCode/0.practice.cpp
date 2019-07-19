/*************************************************************************
	> File Name: 0.practice.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月17日 星期三 17时02分16秒
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
#include <stack>
#define MAX 100000

int arr[MAX + 5];
long long l[MAX + 5], r[MAX + 5];

int main() {
    int n;
    cin >> n;
    stack<int> s;
    arr[0] = arr[n + 1] = -1;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];   
    }

    s.push(0);
    for(int i = 1; i <= n; i++) {
        while(arr[s.top()] >= arr[i]) s.pop();
        l[i] = i - s.top();
        s.push(i);
    }
    
    while(!s.empty()) s.pop();

    s.push(n + 1);
    for(int i = n; i >= 1; i--) {
        while(arr[s.top()] >= arr[i]) s.pop();
        r[i] = s.top() - i;
        s.push(i);
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] * (r[i] + l[i] - 1));
    }
    cout << ans << endl;
    
    return 0;
}
