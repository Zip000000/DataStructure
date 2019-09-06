/*************************************************************************
	> File Name: P.最大子序和.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月06日 星期五 17时18分15秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <deque>
using namespace std;
#define MAX_N 300000
int arr[MAX_N + 5];

int main() {
    deque<int> deq;
    
    int n, m;
    cin >> n >> m;
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    deq.push_back(0);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] - arr[deq.front()]);
        while (!deq.empty() && arr[deq.back()] >= arr[i]) {
            deq.pop_back();
        }
        deq.push_back(i);
        if (!deq.empty() && i - deq.front() >= m) deq.pop_front();
    }
    
    cout << ans << endl;
    
    return 0;
}
