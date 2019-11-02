/*************************************************************************
	> File Name: 250.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月02日 星期三 10时43分17秒
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
#define MAX_N 1000000
long long arr[MAX_N + 5];

int main() {
    long long n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    long long ave = sum / n;
    for (int i = 1; i < n - 1; i++) {

    }
    
    
    
    return 0;
}
