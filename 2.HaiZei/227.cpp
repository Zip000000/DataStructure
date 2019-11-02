/*************************************************************************
	> File Name: 227.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月30日 星期一 23时34分19秒
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

long long get_ans(long long a, long long b, long long p) {
    long long ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;

    cout << get_ans(a, b, p) << endl;
    
    
    return 0;
}
