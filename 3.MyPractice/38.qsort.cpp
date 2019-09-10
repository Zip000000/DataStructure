/*************************************************************************
	> File Name: 38.qsort.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月08日 星期日 09时51分50秒
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

#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}

void select_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (num[min] > num[j]) min = j;
        }
        swap(num[i], num[min]);
    }
}


void quick_sort(int *num, int l, int r) {
    if (r <= l) return ;
    int x = l, y = r, z = num[l];

    while (x < y) {
        while (x < y && num[y] >= z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

int binary_search(int *num, int key, int l, int r) {
    int mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (num[mid] == key) return mid;
        if (num[mid] > key) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main() {
    int num[] = {1,5,9,7,6,8,4,3,2,0};
    int n = sizeof(num) / 4;
    cout << sizeof(num) / 4 << endl;
    quick_sort(num, 0, sizeof(num)/4 - 1);
    for (int i = 0; i < n; i++) {
        cout << num[i] << " " ;
    }
    for (int i = 0; i < n; i++) {
        cout << binary_search(num, num[i], 0, n - 1) << endl;
    }
    cout << endl;
}
