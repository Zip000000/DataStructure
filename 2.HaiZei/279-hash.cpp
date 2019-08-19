/*************************************************************************
	> File Name: 279-hash.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月19日 星期一 14时46分32秒
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
#define BASE 31
#define MO_P 10000009
char str1[MAX_N * 2 + 1], str2[MAX_N];
long long h[(MAX_N << 1) + 5], base[MAX_N + 5];

void init() {
    base[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        base[i] = base[i - 1] * BASE % MOD_P;
    }
    return ;
}

int main() {
    init();
    scanf("%s%s", str1, str2);
    int len1 = strlen(str1), len2 = strlen(str2);

    
    
    return 0;
}
