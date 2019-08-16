/*************************************************************************
	> File Name: test.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月16日 星期五 19时15分19秒
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


char * longestPalindrome(char * s){
    int len = strlen(s);
    int max = 0, max_id = 0;
    for (int i = 0; s[i]; i++) {
        int j = 0;
        while (i + j < len && i - j >= 0 && s[i + j] == s[i - j]) {
            j++;
        }
        if (j > 0) j -= 1;
        int tmp = 2 * j + 1;
        if (tmp > max) max = tmp, max_id = i - j;
        if (i != len && s[i] == s[i + 1]) {
            int i1 = i;
            int i2 = i + 1;
            int j2 = 0;
            while (i2 + j < len && i1 - j >= 0 && s[i2 + j] == s[i1 - j]) {
                j2++;
                printf("in while2 len = %d i1 + j = %d i1 - j = %d\n", len, i1 + j, i1 - j);
            }
            if (j2 > 0) j2 -= 1;
            tmp = 2 * j2 + 2;
            if (tmp > max) max = tmp, max_id = i - j2;
        }
    }
    // printf("maxlen = %d max_id = %d\n", max, max_id);
    char *ret  = (char *)malloc(sizeof(char) * 1005);
    strncpy(ret, s + max_id, max);
    ret[max] = 0;
    // printf("s = %s\n", ret);
    return ret;
}


int main() {
    char s[1005] = {0};
    scanf("%s", s);
    printf("%s\n", longestPalindrome(s));


    return 0;
}
