/*************************************************************************
	> File Name: 303.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月31日 星期六 19时06分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <queue>
using namespace std;

#define MAX_N 1000

int num[MAX_N + 5][MAX_N + 5];

int bfs(int x, int y) {
    queue<int> q;
    
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bfs(i, j);
        }
    }
    
    
    return 0;
}
