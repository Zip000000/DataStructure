/*************************************************************************
	> File Name: 295.LeetCode.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月11日 星期日 11时46分03秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}

#define BIG 1
#define SMALL 0
typedef struct heap{
    int *data;
    int cnt, size;
    int flag;
} heap;

typedef struct {
    heap *big;
    heap *small;
    int numcnt;
} MedianFinder;

heap *heap_init(int flag) {
    heap *h = (heap *)malloc(sizeof(heap));
    h->cnt = 0;
    h->size = 32;
    h->flag = flag;
    h->data = (int *)malloc(sizeof(int) * (h->size + 1));
    return h;
}

int top(heap *h) {
    return h->data[1];
}

void expand(heap *h) {
    h->size *= 2;
    h->data = (int *)realloc(h->data, sizeof(int) * (h->size  + 1));
}

void up_update(heap* h, int n, int ind) {
    int *arr = h->data;
    if (h->flag == BIG) {
        while (ind != 1 && arr[ind / 2] < arr[ind]) {
            swap(arr[ind], arr[ind / 2]);
            ind = ind / 2;
        }
    } else {
        while (ind != 1 && arr[ind / 2] > arr[ind]) {
            swap(arr[ind], arr[ind / 2]);
            ind = ind / 2;
        }
    }
}

void down_update(heap *h, int n, int ind) {
    int *arr = h->data;
    if (h->flag == BIG) {
        while (ind * 2 <= n) {
            int max_sub = ind;
            if (arr[ind * 2] > arr[max_sub]) max_sub = ind * 2;
            if (ind * 2 + 1 <= n && arr[ind * 2 + 1] > arr[max_sub]) max_sub = ind * 2 + 1;
            if (max_sub == ind) break;
            swap(arr[max_sub], arr[ind]);
            ind = max_sub;

        } 
    } else {
        while (ind * 2 <= n) {
            int max_sub = ind;
            if (arr[ind * 2] < arr[max_sub]) max_sub = ind * 2;
            if (ind * 2 + 1 <= n && arr[ind * 2 + 1] < arr[max_sub]) max_sub = ind * 2 + 1;
            if (max_sub == ind) break;
            swap(arr[max_sub], arr[ind]);
            ind = max_sub;
        } 

    }
}

void push(heap *h, int val) {
    if (h->cnt == h->size) expand(h);
    h->data[++h->cnt] = val;
    up_update(h, h->cnt, h->cnt);
}

int pop(heap *h) {
    int ret  = top(h);
    h->data[1] = h->data[h->cnt];
    down_update(h, h->cnt - 1, 1);
    h->cnt--;
    return ret;
}

void heap_free(heap *h) {
    if (h == NULL) return;
    free(h->data);
    free(h);
}
/** initialize your data structure here. */


MedianFinder* medianFinderCreate() {
    MedianFinder *m = (MedianFinder *)malloc(sizeof(MedianFinder));
    m->big = heap_init(BIG);
    m->small = heap_init(SMALL);
    m->numcnt = 0;
    return m;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    //printf("in addnum\n");
    if (num < obj->big->data[1]) {
        push(obj->big, num);
    } else {
        push(obj->small, num);
    }
    obj->numcnt++;

    if (obj->big->cnt > obj->small->cnt + 1) {
        int tmp = pop(obj->big);
        push(obj->small, tmp);
    } else if (obj->small->cnt > obj->big->cnt + 1) {
        //printf("in addnum befor judge smallcnt = %d bigsnt = %d\n", obj->small->cnt, obj->big->cnt);
        //printf("in addnum after judge smallcnt = %d bigsnt = %d\n", obj->small->cnt, obj->big->cnt);
        int tmp = pop(obj->small);
        push(obj->big, tmp);
    }
    //printf("in addnum add over bigcnt = %d smallcnt = %d\n", obj->big->cnt, obj->small->cnt);
}

double medianFinderFindMedian(MedianFinder* obj) {

    if (obj->numcnt % 2 == 0) {
        printf("(%d + %d) / 2\n", obj->big->data[1], obj->small->data[1]);
        return ((double)obj->big->data[1] + (double)obj->small->data[1]) / 2 ;
    } else {
        return (obj->big->cnt > obj->small->cnt ? obj->big->data[1] : obj->small->data[1]);
    }

}

void medianFinderFree(MedianFinder* obj) {
    if (obj == NULL) return ;
    heap_free(obj->big);
    heap_free(obj->small);
    free(obj);
}

void output(MedianFinder *obj) {
    printf("big : ");
    for (int i = 1; i <= obj->big->cnt; i++) {
        printf("%d ", obj->big->data[i]);
    }
    printf("\n");
    printf("small : ");
    for (int i = 1; i <= obj->small->cnt; i++) {
        printf("%d ", obj->small->data[i]);
    }
    printf("\n");
}

int main() {
    MedianFinder *obj = medianFinderCreate();
    while (1) {
        int n;
        scanf("%d", &n);
        medianFinderAddNum(obj, n);
        output(obj);
        printf("%lf\n", medianFinderFindMedian(obj));
    }
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/
