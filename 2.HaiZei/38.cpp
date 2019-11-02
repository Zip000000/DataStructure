/*************************************************************************
	> File Name: 38.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月02日 星期三 22时51分07秒
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

#define MAX_N 100 
typedef struct Data  {
    int num[40];
    int flag;
} Data;
Data dp[MAX_N + 5][3];
Data ans;

Data add(const Data &a, const Data &b) {
    Data ret;
    const int *aa = a.num, *bb = b.num;
    int *cc = ret.num;
    int wei = max(a.flag, b.flag);
    for (int i = 0; i < wei; i++) {
        cc[i] = aa[i] + bb[i];
    }
    for (int i = 0; i < wei; i++) {
        if (cc[i] >= 10) cc[i + 1] = cc[i] % 10;
        cc[i] /= 10;
    }
    ret.flag = wei;
    ret.flag += (cc[wei + 1] != 0);
    return ret;
}
void print(const Data &a) {
    for (int i = 0; i < a.flag; i++) cout << a.num[i];
    cout << endl;
}
int main() {
    dp[1][0].num[0] = 1;
    dp[1][0].flag = 1;
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        cout << "i = " << i << endl;
        dp[i][0] = add(dp[i - 1][0], dp[i - 1][2]);
        dp[i][1] = add(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = dp[i - 1][1];
    }
    cout << "after " << endl;
    for (int i = 0; i < 3; i++) ans = add(ans, dp[n][i]);
    print(ans);

    return 0;
}
