/*************************************************************************
	> File Name: 183.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 14时43分09秒
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

int f(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n & 1 == 0) return 3 * f(n / 2) - 1;
    else return 3 * f((n + 1) / 2) - 1;
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    
    return 0;
}
