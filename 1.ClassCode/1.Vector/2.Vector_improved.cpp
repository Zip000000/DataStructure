/*************************************************************************
	> File Name: 1.Vector.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年06月30日 星期日 15时17分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

Vector *init(int n) { 
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *) malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;
}
int expand(Vector *vec) {
    int  new_size = 2 * vec->size;
    int *p = (int *)realloc(vec->data, sizeof(int) * new_size); // 方式realloc申请空间失败，原data内存空间丢失。
    if(p == NULL) return 0;
    vec->data = p;
    vec->size = new_size;
    return 1;

}

int insert(Vector *vec, int ind, int val) {
    if(vec == NULL) return 0;
    if(vec->length == vec->size) {
        if(!expand(vec)) return 0;
        printf("expand size to %d!\n", vec->size);
    }
    if(ind < 0 || ind > vec->length) return 0;
    
    for(int i = vec->length; i > ind; i--) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[ind] = val;
    vec->length+=1;
    return 1;
}

int erase(Vector *vec, int ind) {
    if (vec == NULL) return 0;
    if (vec->length == 0) return 0;
    if(ind < 0 || ind >= vec->length) return 0;

    for(int i = ind + 1; i < vec->length; i++) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->length-=1;
    return 1;
}

void clear(Vector *vec) {
    if(vec == NULL) return;
    free(vec->data);
    free(vec);
    return;
}

void output(Vector *vec) {
    printf("arr(%d) = [", vec->length);
    for(int i = 0; i < vec->length; i++) {
        i == 0 || printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Vector *vec = init(1);
    int op, ind, val;
    for(int i = 0; i < MAX_OP; i++) {
        op = rand() % 4;
        ind = rand() % (vec->length + 2);
        val = rand() % 100;
        switch(op) {
            case 2:
            case 3:
            case 0:
            printf("insert %d at %d to vector. return = %d\n", val, ind, insert(vec, ind, val));
            break;
            case 1:
            printf("erase item at %d from vector. return = %d\n", ind, erase(vec, ind));
            break;
        }
        output(vec);
    }
    
    return 0;
}

