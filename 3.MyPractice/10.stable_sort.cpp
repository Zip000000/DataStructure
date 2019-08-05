/*************************************************************************
	> File Name: 10.stable_sort.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月23日 星期二 19时55分25秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a, b) { \
    a ^= b; b ^= a; a ^= b; \
}

void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; --j) {
            swap(num[j], num[j - 1]);
        }
    }
}

void bubble_sort(int *num, int n) {
    int times = 1;
    for (int i = 1; i < n && times; i++) {
        times = 0;
        for (int j = 0; j < n - i; j++) {
            if(num[j] <= num[j + 1]) continue;
            swap(num[j], num[j + 1]);
            times++;
        }
    }
    return;
}

void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && num[l > num[r]]) {
            swap(num[l], num[r]);
        }
        return ;
    }
    int mid = (r + l) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || p1 <= mid && num[p1] <= num[p2]) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return ;
}



int main() {
    
}
