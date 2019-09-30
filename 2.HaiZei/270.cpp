/*************************************************************************
	> File Name: 270.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月27日 星期五 17时38分13秒
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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    deque<int> que;
    que.push_back(0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int ind = arr[i] - arr[que.front()];
        ans = (ans > ind ? ans : ind);
        while (!que.empty() && arr[i] <= arr[que.back()]) que.pop_back();
        que.push_back(i);
        if (i - que.front() >= m) que.pop_front();
    }
    cout << ans << endl;
    return 0;
}
