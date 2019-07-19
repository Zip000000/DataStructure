/*************************************************************************
	> File Name: 3.Stack.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月17日 星期三 14时42分24秒
 ************************************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Stack {
    int *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return (s->top == -1);
}

int top(Stack *s) {
    if (s == NULL) return 0;
    return s->data[s->top];
}

int push(Stack *s, int val) {
    if(s == NULL) return 0;
    if(s->top + 1 == s->size) return 0;
    s->data[++s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if(s == NULL) return 0;
    if(empty(s)) return 0;
    s->top -= 1;
    return 1;
}


void clear(Stack *s) {
    if(s == NULL) return;
    free(s->data);
    free(s);
    return;
}

void output(Stack *s) {
    printf("-----------stack(%d) = [", s->top + 1);
    for(int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("]\n");
}

int main() {
    #define MAX_OP 20
    Stack *s = init(MAX_OP);
    srand(time(0));
    
    for(int i = 0; i < MAX_OP; i++) {
        int op = rand() % 2, val = rand() % 10;
        switch(op) {
            case 0: printf("push %d ,ret = %d\n", val, push(s, val));
            break;
            case 1: printf("pop  ret = %d\n", pop(s));
            break;
        }
        output(s);
    }

    return 0;
}
