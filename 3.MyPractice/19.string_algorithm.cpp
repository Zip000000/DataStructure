/*************************************************************************
	> File Name: 19.string_algorithm.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月12日 星期一 16时19分42秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BruteForce(char *str, char *pattern) {
    for (int i = 0; str[i]; i++) {
        int flag = 1;
        for (int j = 0; pattern[j]; j++) {
            if (str[i + j] == pattern[j]) continue;
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}

int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(char) * strlen(pattern));
    next[0] = -1;
    for (int i = 1; pattern[i]; i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j + 1] == pattern[i]) next[i] = j + 1;

        else (int i = 0;)
    }
    
}

int main() {

    
    
    return 0;
}
