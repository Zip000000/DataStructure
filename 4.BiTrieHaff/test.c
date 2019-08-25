/*************************************************************************
	> File Name: test.c
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月24日 星期六 10时06分16秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned char str[100];
    scanf("%s", str);
    for (int i = 0; str[i]; i++) {
        printf("%d\n", str[i]);

    }

    return 0;
}
