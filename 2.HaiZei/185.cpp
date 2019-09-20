/*************************************************************************
	> File Name: 185.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 14时51分00秒
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
    
    int f[3] = {1, 1, 0};
    
    int i;
    for (i = 2; i < n; i++) {
        f[i % 3] = f[(i + 1) % 3] + f[(i + 2) % 3];
    }
    cout << f[(i - 1) % 3] << endl;

    
    
    return 0;
}
