/*************************************************************************
	> File Name: 186.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 14时55分49秒
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
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 0; i < n;) {
        i += arr[i];
        cnt += 1;
    }
    cout << cnt << endl;
    
    return 0;
}
