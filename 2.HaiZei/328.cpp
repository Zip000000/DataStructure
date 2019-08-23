/*************************************************************************
	> File Name: 328.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月23日 星期五 19时02分42秒
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

#define MAX_N 200000
long long c[MAX_N + 5];
inline long long lowbit(long long x) { return x & (-x); }
void add(long long x, long long val, long long n) {
    while (x <= n) c[x] += val, x += lowbit(x);
}
long long query(long long x) {
    long long sum = 0;
    while (x) sum += c[x], x -= lowbit(x);
    return sum;
}

int main() {
    long long n;
    cin >> n;
    long long ans1 = 0, ans2 = 0;
    long long now, pre = 0;
    for (int i = 1; i <= n; i++) {
        cin >> now;
        long long val1 = query(now); //前小
        long long val2 = now - 1 - val1;
        long long val3 = (i - 1 - val1); //前大
        long long val4 = (n - i - val2);
        ans1 += val1 * val2;
        ans2 += val3 * val4;
        add(now, 1, n);
    }
    cout << ans2 << " " << ans1 << endl;
    
    
    return 0;
}
