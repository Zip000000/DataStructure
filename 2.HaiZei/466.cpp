/*************************************************************************
	> File Name: 466.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 15时43分58秒
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

bool is_hui(int n) {
    if (n < 10) return true;
    int tmp = 0;
    while (n > tmp) {
        tmp *= 10;
        tmp += n % 10;
        n /= 10;
        if (tmp == 0) return false;
    }
    if (n < tmp) tmp /= 10;
    return (n == tmp);
}

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (!is_hui(i)) continue;
        cnt += 1;
    }
    cout << cnt << endl;
    return 0;
}
