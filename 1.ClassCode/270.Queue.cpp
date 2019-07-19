/*************************************************************************
	> File Name: 270.Queue.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月17日 星期三 18时07分21秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

#define MAX 300000
int q[MAX + 5], head, tail;
long long arr[MAX + 5];

int main() {

    long long  n, m;
    cin >> n >> m;
    arr[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    head = tail = 0;
    q[tail++] = 0;

    long long ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = max(ans, arr[i] - arr[q[head]]);
        while(tail > head && arr[q[tail - 1]] >= arr[i]) tail--;
        q[tail++] = i;
        if(q[head] == i - m) head++;
    }
    cout << ans << endl;
    return 0;
}
