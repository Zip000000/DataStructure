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
}

int sunday(char *s, char *t) {
}

int shift_and(char *s, char *t) {
}

int KMP(char *s, char *t) {
}

int main() {
    
    scanf("%s%s", text, pattern);
    
    TEST(brute_force, text, pattern);    
    TEST(KMP, text, pattern);    
    TEST(sunday, text, pattern);    
    TEST(shift_and, text, pattern);    
    
    return 0;
}
