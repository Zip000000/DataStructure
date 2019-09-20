/*************************************************************************
	> File Name: 184.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 14时47分02秒
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

int main() {
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        ans += 1;
        ans *= 2;
    }
    cout << ans << endl;
    
    return 0;
}
