/*************************************************************************
	> File Name: S.循环的字符串.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月06日 星期五 21时14分11秒
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

int main() {
    int n;
    cin >> n;
    char *str = (char *)calloc(sizeof(char), n + 5);
    int *next = (int *)calloc(sizeof(int), n + 5);
    int *circle_len = (int *)calloc(sizeof(int), n + 5);
    cin >> str;
    next[0] = -1;
    int j = next[0];
    for (int i = 1; str[i]; i++) {
        while (j != -1 && str[i] != str[j + 1]) j = next[j];
        if (str[i] == str[j + 1]) j += 1;
        next[i] = j;
    }

    for (int i = 0; str[i]; i++)  {
    }
    

    for (int i = 0; i < str[i]; i++) {
        if (next[i] == -1 || i - next[i] != circle_len[next[i]]) {
            circle_len[i] = i + 1;
        } else {
            circle_len[i] = circle_len[next[i]];
        }
    }

    for (int i = 0; str[i]; i++) {
        if (circle_len[i] == i + 1) continue;
        cout << i + 1 << " " << (i + 1) / circle_len[i] << endl;
    }


    
    return 0;
}
