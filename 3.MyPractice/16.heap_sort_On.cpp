/*************************************************************************
	> File Name: 16.heap_sort_On.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月10日 星期六 14时39分28秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}
void down_update(int *arr, int n, int ind) {
    while (ind * 2 <= n) {
        int max_sub = ind, l = ind * 2, r = ind * 2 + 1;
        if (arr[l] > arr[max_sub]) max_sub = l;
        if (r <= n && arr[r] > arr[max_sub]) max_sub = r;
        if (ind == max_sub) break;
        swap(arr[max_sub], arr[ind]);
        ind = max_sub;
    }
}
void heap_sort(int *arr, int n) {
    arr--;
    //建堆
    for (int i = n / 2; i >= 1; i--) {
        down_update(arr, n, i);
    }
    //弹出
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);
        down_update(arr, i - 1, 1);
    }
}
/*
*/

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    srand(time(0));
    #define MAX_OP 20
    int *arr = (int *)malloc(sizeof(int) * MAX_OP);

    for (int i = 0; i < MAX_OP; i++) {
        arr[i] = rand() % 100;
    }
    output(arr, MAX_OP);
    heap_sort(arr, MAX_OP);
    output(arr, MAX_OP);

    return 0;
}
