/*************************************************************************
	> File Name: 11.heap_sort.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月05日 星期一 14时58分50秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}
#define L(a) ((a)*2)
#define R(a) ((a)*2+1)
#define F(a) (a/2)
#define MAX_N 1000
int num[MAX_N + 5], n;

void heap_sort(int *num, int n) {
    num--;
    
    for (int i = 2; i <= n; i++) {
        int ind = i;
        while (ind != 1 && num[F(ind)] < num[ind]) {
            swap(num[F(ind)], num[ind]);
            ind = F(ind);
        }
    }

    for (int i = n; i >= 1; i--) {
        swap(num[1], num[i]);
        int ind = 1;
        while (L(ind) <= i - 1) {
            int max_sub = ind;
            if (num[L(ind)] > num[ind]) max_sub = L(ind);
            if (R(ind) <= i - 1 && num[R(ind)] > num[max_sub]) max_sub = R(ind);
            if (max_sub == ind) break;
            swap(num[ind], num[max_sub]);
            ind = max_sub;
        }
    }

}




int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", num + i);
    heap_sort(num, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    
    
    
    return 0;
}
