/*************************************************************************
	> File Name: 270.sort_Queue.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月23日 星期二 14时44分48秒
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

int s[MAX + 5];
int q[MAX + 5];
int main() {
    long long n, m;
    cin >> n >> m;
    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    int head = 0, tail = 0;
    q[tail++] = 0;
    int ans = -2147483647;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, s[i] - s[q[head]]);
        while (tail - head > 0 && s[i] <= s[q[tail - 1]]) tail--;
        q[tail++] = i;
        while (q[tail-1] - q[head] > m) head++;
    }
    printf("%d\n", ans);
    
    
    return 0;
}
