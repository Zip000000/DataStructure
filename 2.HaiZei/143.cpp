/*************************************************************************
	> File Name: 143.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 13时33分47秒
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


inline bool is_sqr(int n) {
    return (n != 0 && pow((int)sqrt(n), 2) == n);
}
int main()  {
    int a, b;
    cin >> a >> b;
    
    int *prime = new int[b + 5];
    int *is_prime = new int[b + 5];

    for (int M = 2; M <= b; M++) {
        if (is_prime[M] == 0) prime[++prime[0]] = M;
        for (int j = 1; j <= prime[0]; j++) {
            if (M * prime[j] > b) break;
            is_prime[M * prime[j]] = 1;
            if (M % prime[j] == 0) break;
        }
    }
    
    int cnt = 0;
    for (int i = a; i <= b; i++) {
        if (i % 6 != 0) continue;
        int num1 = i / 100;
        if (is_prime[num1] == 1) continue;
        int num2 = i % 100;
        if (!is_sqr(num2)) continue;
        cnt += 1;
        cnt == 1 || printf(" ");
        printf("%d", i);
    }
    cout << endl <<  cnt << endl;
    
    return 0;
}
