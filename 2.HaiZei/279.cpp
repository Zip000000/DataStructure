/*************************************************************************
	> File Name: 279.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月19日 星期一 14时30分02秒
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


int sunday(char *s, char *t) {
    int ind[128] = {0};
    int len1 = strlen(s);
    int len2 = strlen(t);
    
    for (int i = 0; i < 128; i++) ind[i] = len2 + 1;
    for (int  i = 0; t[i]; i++) ind[t[i]] = len2 - i;
    for (int i = 0, I = len1 - len2 + 1; i < I;) {
        int flag = 1;
        for (int j = 0; j < len2; j++) {
            if (t[j] == s[i + j]) continue;
            i += ind[s[i + len2]];
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1; 
}

char text[MAX_N + 5], pattern[MAX_N + 5];
int main() {
    
    
    
    return 0;
}

