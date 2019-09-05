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
#include <queue>
using namespace std;

#define MAX_N 1000
#define TEST(func, a, b) { \
    printf("TEST %s(%s, %s) = %d\n", #func, a, b, func(a, b));\
}

char text[MAX_N + 5], pattern[MAX_N + 5];


int brute_force(char *s, char *t) {
    int slen = strlen(s), tlen = strlen(t);
    for (int i = 0, I = slen - tlen + 1; i < I; i++) {
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
    int slen = strlen(s), tlen = strlen(t);
    int ind[128];
    for (int i = 0; i < 128; i++) ind[i] = tlen + 1;
    for (int i = 0; i < tlen; i++) ind[t[i]] = tlen - i;

    for (int i = 0, I = slen - tlen + 1; i < I; ) {
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
    int slen = strlen(s), tlen = strlen(t);
    int code[128] = {0};
    for (int i = 0; i < tlen; i++) {
        code[t[i]] |= (1 << i);
    }

    int p = 0;
    int flag = (1 << (tlen - 1));
    for (int i = 0; s[i]; i++) {
        p <<= 1;
        p |= 1;
        p &= code[s[i]];
        if (p & flag) return (i - tlen + 1);
    }
    return -1;
}



int shift_and_best(char *s, char *t) {
    int slen = strlen(s), tlen = strlen(t);
    char **code = (char **)malloc(sizeof(char *) * 128);
    for (int i = 0; i < 128; i++) code[i] = (char *)calloc(sizeof(char), (tlen + 1));

    for (int i = 0; t[i]; i++) {
        code[t[i]][i] = 1;
    }
    queue<char> q;
    for (int i = 0; s[i]; i++) {

    }
}
int KMP(char *s, char *t) {
    int slen = strlen(s), tlen = strlen(t);
    
    int *next = (int *)malloc(sizeof(int) * tlen);
    next[0] = -1;
    int j = next[0];
    for (int i = 1; t[i]; i++) {
        while (j != -1 && t[i] != t[j + 1]) j = next[j];
        if (t[i] == t[j + 1]) j += 1;
        next[i] = j;
    }

    j = -1;
    for (int i = 0; s[i]; i++) {
        while (j != -1 && s[i] != t[j + 1]) {
            j = next[j];
        } 
        if (s[i] == t[j + 1]) {
            j += 1;
            if (j == tlen - 1) return (i - tlen + 1);
            continue;
        }
    }
    return  -1;
}
int main() {
    
    scanf("%s%s", text, pattern);
    
    TEST(brute_force, text, pattern);    
    TEST(sunday, text, pattern);    
    TEST(shift_and, text, pattern);    
    TEST(KMP, text, pattern);    
    //TEST(shift_and_char, text, pattern);    
    
    return 0;
}


/*
int shift_and_char(char *s, char *t) {
}
*/


/*
    int len1 = strlen(s), len2 = strlen(t);
    int *next = (int *)malloc(sizeof(int) * len2);
    next[0] = -1;
    int j = -1;
    for (int i = 1; t[i]; i++) {
        while (j != -1 && t[i] != t[j + 1]) j = next[j];
        if (t[i] == t[j + 1]) j += 1;
        next[i] = j;
    }

    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && t[j + 1] != s[i]) j = next[j];
        if (t[j + 1] == s[i]) j += 1;
        if (t[j + 1] == 0) return i - len2 + 1;
    }
    return -1;
    */


/*
int KMP(char *s, char *t) {
    int slen = strlen(s), tlen = strlen(t);

    int *next = (int *)malloc(sizeof(int) * (tlen + 1));
    
    next[0] = -1;
    int j = next[0];
    for (int i = 1; t[i]; i++) {
        while (j != -1 && t[i] != t[j + 1]) j = next[j];
        if (t[i] == t[j + 1]) j += 1;
        next[i] = j;
    }
    int k = 0;
    for (int i = 0, I = slen - tlen + 1; i < I; i++) {
        if (k < tlen && s[i] == t[k]) {
            k++;
            if (k == tlen) return (i - tlen + 1);
            continue;
        }
        k -= 1;
        while (k != -1 && s[i] != t[k + 1]) k = next[k];
        k += 1;
    }
    return -1;
}
*/
