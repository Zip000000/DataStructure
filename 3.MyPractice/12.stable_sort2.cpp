/*************************************************************************
	> File Name: 12.stable_sort2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月05日 星期一 19时27分05秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) tmp; \
    tmp = a; \
    a = b; \
    b = tmp; \
}


#define TEST(arr, n, func, args...) { \
    int *num = (int *)malloc(sizeof(int) * n); \
    memcpy(num, arr, sizeof(int) * n); \
    output(num, n); \
    printf("%s = ", #func); \
    func(args); \
    output(num, n); \
    free(num); \
}

void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j != 0 && num[j] < num[j - 1]) {
            swap(num[j], num[j - 1]);
            j--;
        } 
    }
   /*
    for (int i = 1; i < n; i++) {
        int j = i;
        for (;j > 0 && num[j] < num[j - 1];) {
            swap(num[j], num[j - 1]);
            j--;        
        }
    }
    */
        return ;
}

void bubble_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        int times = 0;
        for (int j = 0; j < n - i; j++) {
            if (num[j] <= num[j + 1]) continue;
            swap(num[j], num[j + 1]);
            times++;
        }
        if (times == 0) break;
    }
}

void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return ;
    }

    int mid = (l + r) >> 1;
    
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);

    int *tmp = (int *)malloc(sizeof(int) * (r - l + 1));
    
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || p1 <= mid && num[p1] <= num[p2]) {
            tmp[k++] = num[p1++];
        } else {
            tmp[k++] = num[p2++];
        }
    }
    memcpy(num + l, tmp, sizeof(int) * (r - l + 1));
    free(tmp);
}

void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
    return;

}
void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf(" %d", num[i]);
    }
    printf(" ]\n");
}

int main() {
    srand(time(0));
    #define MAX_OP 20

    int arr[MAX_OP];
    randint(arr, MAX_OP);

    TEST(arr, MAX_OP, insert_sort, num, MAX_OP);
    TEST(arr, MAX_OP, bubble_sort, num, MAX_OP);
    TEST(arr, MAX_OP, merge_sort, num, 0, MAX_OP - 1);


    return 0;
}
