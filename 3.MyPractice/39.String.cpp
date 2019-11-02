/*************************************************************************
	> File Name: 39.String.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月28日 星期一 11时02分01秒
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
#define MAX_N 1000
char text[MAX_N + 5], pattern[MAX_N + 5];

int brute_force(char *s, char *t) {
    int len1 = strlen(s), len2 = strlen(t);
    for (int i = 0, I = len1 - len2 + 1; i < I; i++) {
        int flag = 1;
        for (int j = 0; t[j]; j++) {
            if (t[j] == s[i + j]) continue;
            flag = 0;
            break;
        }
        if (flag) return i;
    }
}

int sunday(char *s, char *t) {
    int code[128];
    int len1 = strlen(s);
    int len2 = strlen(t);
    for (int i = 0; i < 128; i++) code[i] = len2 + 1;
    for (int i = 0; t[i]; i++) code[t[i]] = len2 - i;
    for (int i = 0, I = len1 - len2 + 1; i < I;) {
        int flag = 1;
        for (int j = 0; j < len2; j++) {
            if (t[j] == s[i + j]) continue;
            i += code[i + len2];
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}

int main() {
    scanf("%s%s", text, pattern);
    
    
    return 0;
}
