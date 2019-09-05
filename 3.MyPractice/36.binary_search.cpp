/*************************************************************************
	> File Name: 36.binary_search.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月03日 星期二 18时59分06秒
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1 2 3 4 5 6 7 8  9 
int binary_search(int *num, int n, int x) {
    int head = 0, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}
// 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

//0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail ) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {
    
    
    
    
    return 0;
}
