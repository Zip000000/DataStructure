/*************************************************************************
	> File Name: 79.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月23日 星期五 20时21分03秒
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

#define MAX_N 10000000

int prime[MAX_N + 5];
int is_prime[MAX_N + 5];

int main() {
    int a, b;
    cin >> a >> b;
    for (int M = 2 ; M <= b; M++) {
        if (is_prime[M] == 0) prime[++prime[0]] = M;
        for (int j = 1; j <= prime[0]; j++) {
            if (M * prime[j] > b) break;
            is_prime[M * prime[j]] = 1;
            if (M % prime[j] == 0) break;
        }
    }
    
    
    for (int i = 1; i <= prime[0]; i++) {
        if (prime[i] < a) continue;
        printf("%d\n", prime[i]);
    }
    
    return 0;
}
