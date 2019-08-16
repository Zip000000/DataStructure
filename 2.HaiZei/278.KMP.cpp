/*************************************************************************
	> File Name: 278.KMP.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月16日 星期五 16时08分16秒
 ************************************************************************/

#include <string.h>
#include <stdio.h>
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
char str[MAX_N + 5];

int nxt[MAX_N + 5];
int ans[MAX_N + 5];

void get_nxt(char *str, int *nxt) {
    int j = -1;
    nxt[0] = -1;
    for (int i = 1; str[i]; i++) {
        while (j != -1 && str[j + 1] != str[i]) j = nxt[j];
        if (str[j + 1] == str[i]) j += 1;
        nxt[i] = j;
    }
    return;
}
int main() {
    int n;
    cin >> n;
    cin >> str;
    get_nxt(str, nxt);
    for (int i = 0; i < n; i++) {
        if (nxt[i] == -1 || i - nxt[i] != ans[nxt[i]]) {
            ans[i] = i + 1;
        } else {
            ans[i] = ans[nxt[i]];
        } 
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == i + 1) continue;
        cout << i + 1 << " " << (i + 1) / ans[i] << endl;
    }
    return 0;
}
