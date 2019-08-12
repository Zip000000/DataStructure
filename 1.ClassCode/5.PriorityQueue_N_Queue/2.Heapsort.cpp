/*************************************************************************
	> File Name: 2.Heapsort.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月09日 星期五 18时57分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_OP 20

#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}

void downUpdate(int *arr, int n, int ind) {
    while (ind * 2 <= n) {
        int tmp = ind, l = ind * 2, r = ind * 2 + 1;
        if (arr[l] > arr[tmp]) tmp = l;
        if (r <= n && arr[r] > arr[tmp]) tmp = r;
        if (tmp == ind) break;
        swap(arr[tmp], arr[ind]);
        ind = tmp;
    }
}

void heap_sort(int *arr, int n) {
    arr--;
    for (int i = n / 2; i >= 1; i--) {
        int ind = i;
        downUpdate(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);
        downUpdate(arr, i - 1, 1);
    }
}

void output(int *arr, int n) {
    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int *arr = (int *)malloc(sizeof(int) * MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        arr[i] = rand() % 100;
    }

    output(arr, MAX_OP);
    heap_sort(arr, MAX_OP);
    output(arr, MAX_OP);
    
    
    return 0;
}
