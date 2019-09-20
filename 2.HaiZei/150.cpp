/*************************************************************************
	> File Name: 150.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 14时20分22秒
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
#define MAX_N 200
int arr[MAX_N + 5][MAX_N + 5];
int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            j == n - 1 || cout << " ";
            cout << arr[j][i];
        }
        cout << endl;
    }

    
    return 0;
}
