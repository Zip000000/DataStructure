/*************************************************************************
	> File Name: 13.heap_sort2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月09日 星期五 16时01分49秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}

#define MAX 1000
int num[MAX + 5], n;

void heap_sort(int *num, int n) {
    num -= 1;
    for (int i = 2; i <= n; i++) {
        int ind = i;
        while (ind != 1 && num[ind] > num[ind >> 1]) {
            swap(num[ind], num[ind >> 1]);
            ind >>= 1;
        }
    }

    for (int i = n; i >= 2; i--) {
        swap(num[i], num[1]);
        int ind = 1;
        while (ind * 2 < i) {
            int max = ind;
            if (num[ind * 2] > num[ind]) max = ind * 2;
            if (ind * 2 + 1 < i && num[ind * 2 + 1] > num[max]) max = ind * 2 + 1;

            if (max == ind) break;
            swap(num[max], num[ind]);
            ind = max;
        }
    }
}

int main() {
    scanf("%d", &n);    
    for (int i = 0; i < n; i++) scanf("%d", num + i);

    heap_sort(num, n);

    for (int i = 0; i < n; i++) {
        printf("%d", num[i]);
    }
    printf("\n");
    
    
    return 0;
}
