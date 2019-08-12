/*************************************************************************
	> File Name: 15.heap_sort3.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月09日 星期五 16时28分10秒
 ************************************************************************/


#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}

#define MAX 1000
//大顶堆！

#define L(a) ((a)*2)
#define R(a) ((a)*2 + 1)
#define F(a) ((a)/2)

/*
void heap_sort(int *num, int n) {
    num--;
    for (int i = 2; i <= n; i++) {
        int ind = i;
        while (ind != 1 && num[ind] > num[F(ind)]) {
            swap(num[ind], num[F(ind)]);
            ind = F(ind);
        }
    }
    for (int i = n; i >= 2; i--) {
        swap(num[1], num[i]);
        int ind = 1;
        while (L(ind) < i) {
            int max_sub = ind;
            if (num[max_sub] < num[L(ind)]) max_sub = L(ind);
            if (R(ind) < i && num[max_sub] < num[(R(ind))]) max_sub = R(ind);
            if (max_sub == ind) break;
            swap(num[max_sub], num[ind]);
            ind = max_sub;
        }
    }
    return;
}
*/
void heap_sort(int *num, int n) {
    num--;
    for (int i = 2; i <= n; i++) {
        int ind = i;
        while (ind != 1 && num[ind] > num[F(ind)]) {
            swap(num[ind], num[F(ind)]);
            ind = F(ind);
        }
    }
    for (int i = n; i >= 2; i--) {
        swap(num[1], num[i]);
        int ind = 1;
        while (L(ind) < i) {
            int max_sub = ind;
            if (num[max_sub] < num[L(ind)]) max_sub = L(ind);
            if (R(ind) < i && num[max_sub] < num[R(ind)]) max_sub = R(ind);
            
            if (max_sub == ind) break;

            swap(num[max_sub], num[ind]);
            ind = max_sub;
        }
    }
    return;
}

int main() {
    int num[MAX], n;    
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", num + i);
    
    heap_sort(num, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}
