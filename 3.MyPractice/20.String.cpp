/*************************************************************************
	> File Name: 1.String.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月16日 星期五 18时13分54秒
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
#define TEST(func, a, b) { \
    printf("TEST %s(%s, %s) = %d\n", #func, a, b, func(a, b));\
}

char text[MAX_N + 5], pattern[MAX_N + 5];


int brute_force(char *s, char *t) {
    int slen = strlen(s);
    int tlen = strlen(t);
    for (int i = 0; i < slen - tlen + 1; i++) {
        int flag = 1;
        for (int j = 0; j < tlen; j++) {
            if (s[i + j] == t[j]) continue;
            flag = 0;
        }
        if (flag) return i;
    }
    return -1;
}

int sunday(char *s, char *t) {
    int ind[128] = {0};
    int slen = strlen(s);
    int tlen = strlen(t);
    for (int i = 0; i < 128; i++) ind[i] = tlen + 1;
    for (int i = 0; i < tlen; i++) ind[t[i]] = tlen - i;
    for (int i = 0; i < slen - tlen + 1;) {
        int flag = 1;
        for (int j = 0; j < tlen; j++) {
            if (s[i + j] == t[j]) continue;
            i += ind[s[i + tlen]];
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;

}

int shift_and(char *s, char *t) {
    int code[128] = {0};
    int len = 0;
    for (len = 0; t[len]; len++) {
        code[t[len]] |= (1 << len);
    }

    int p = 0;
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & code[s[i]];
        if (p & (1 << (len - 1))) return i - len + 1;
    }
    return -1;
}


int shift_and_char(char *s, char *t) {
    int tlen = strlen(t);
    int code[128][tlen] = {0};
    
    for (int i = 0; t[i]; i++) {
        code[t[i]][i] = 1;
    }
    int slen = strlen(s);
    char flag[slen + 5];
    for (int i = 0; s[i]; i++) {
        flag[i] = 1;
        int cnt = 0;
        for (int j = 0; j <= i; j++) {
            flag[i - j] &= code[s[i]][j];
        } 
        if (i > tlen && flag[i - tlen] == 1) return i - tlen;
    }
    return -1;
}

/*
int KMP(char *s, char *t) {
    int slen = strlen(s);
    int tlen = strlen(t);
    int *next = (int *)malloc(sizeof(int) * tlen);
    next[0] = -1;
    int j;
    for (int i = 0, j = -1;; i < tlen; i++) {
        while (j != -1 && t[j + 1] != t[i]) j = next[j];
        if (t[j + 1] == t[i]) j += 1;
        next[i] = j;
    }

    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && t[j + 1] !=s[i]) j = next[j];
    }
}
*/
int main() {
    
    scanf("%s%s", text, pattern);
    
    TEST(brute_force, text, pattern);    
    //TEST(KMP, text, pattern);    
    TEST(sunday, text, pattern);    
    TEST(shift_and, text, pattern);    
    TEST(shift_and_char, text, pattern);    
    
    return 0;
}
