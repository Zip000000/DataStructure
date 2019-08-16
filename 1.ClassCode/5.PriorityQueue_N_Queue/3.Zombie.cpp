/*************************************************************************
	> File Name: 3.Zombie.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月14日 星期三 16时46分51秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}

typedef struct Zombie {
    int f, s, id;
} Zombie;

Zombie z[50000 + 5];
typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->cnt = 0;
    q->size = n;
    return q;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int top(priority_queue *q) {
    return q->data[1];
}

int push(priority_queue *q, int val) {
    if (q->cnt == q->size) return 0;

    q->cnt++;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    while (ind >> 1 && z[q->data[ind]].f > z[q->data[ind >> 1]].f) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }

    return 1;
}

int pop(priority_queue *q) {
    if (empty(q)) return 0;
    q->data[1] = q->data[q->cnt--];
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int max_sub = ind;
        if (z[q->data[ind << 1]].f > z[q->data[max_sub]].f) max_sub = ind << 1;
        if ((ind << 1 | 1) <= q->cnt && z[q->data[ind << 1 | 1]].f > z[q->data[max_sub]].f) {
            max_sub = ind << 1 | 1;
        }
        if (max_sub == ind) break;
        swap(q->data[ind], q->data[max_sub]);
        ind = max_sub;
    }
    return 1;
}


void clear(priority_queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return;
}

int main() {
    priority_queue* q[200];
    int flag[200] = {0};
	int t; scanf("%d", &t);
    int min_sub;
    for (int i = 0; i < t; i++) {
        int n; scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int f, s;
            scanf("%d %d", &f, &s);
            z[j].id = j;
            z[j].f = f;
            z[j].s = s;
            if (flag[s]) {
                push(q[s], j);
            } else {
                q[s] = init(50000);
                flag[s] = 1;
                min_sub = s;
                push(q[s], j);
            }
        }
    }

    int fflag = 1;//何时跳跳出
    int timecnt = 0;
    while (fflag != 0) {
        for (int  i = 100; i >= 0; i--) {
            if (flag[i] == 0) continue;
            if (top(q[i]) < top(q[min_sub])) {
                min_sub = i;
			} else if (top(q[i]) == top(q[min_sub])) {
				min_sub = (z[i].id < z[min_sub].id) ? i : min_sub;
        	}
            printf("%d", top(q[min_sub]));
            pop(q[min_sub]);
            if (empty(q[min_sub])) flag[min_sub] = 0;
        }
    
    }
    
    return 0;
}
