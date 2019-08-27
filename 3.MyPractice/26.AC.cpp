/*************************************************************************
	> File Name: 26.AC.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月26日 星期一 14时57分45秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 26
#define BEGIN_LETTER 'a'
typedef struct Node {
    int flag;
    struct Node *next[BASE], *fail;
} Node;



void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

typedef struct Queue {
    Node **data;
    int head, tail, size;
} Queue;

Queue *init_queue(int n) {
    Queue *q = (Queue *)calloc(sizeof(Queue), 1);
    q->data = (Node **)malloc(sizeof(Node *) * n);
    q->head = q->tail = 0;
    return q;
}

Node *front(Queue *q) {
    return q->data[q->head];
}

bool empty(Queue *q) {
    return q->head == q->tail;
}

void push(Queue *q, Node *node) {
    q->data[q->tail++] = node;
}
void pop(Queue *q) {
    if (empty(q)) return;
    q->head++;
}

void clear_queue(Queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return ;
}


Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(), cnt++;
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}

void build_AC(Node *root, int n) {
    Queue *q = init_queue(n + 10);
    root->fail = NULL;
    push(q, root);
    while (!empty(q)) {
        Node *now_node = front(q);
        pop(q);
        for (int i = 0; i < BASE; i++) {
            if (now_node->next[i] == NULL) continue;
            Node *p = now_node->fail;
            while (p && p->next[i] == NULL) p = p->fail;
            if (p == NULL) now_node->next[i]->fail = root;
            else now_node->next[i]->fail = p->next[i];
            push(q, now_node->next[i]);
        }
    }
}

int match(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        while (p && p->next[ind] == NULL) p = p->fail;
        if (p == NULL) p = root;
        else p = p->next[ind];
        Node *q = p;
        while (q) cnt += q->flag, q = q->fail;
    }
    return cnt;
}

int main() {
    Node *root = getNewNode();
    int n, cnt = 0;
    scanf("%d", &n);
    int op;
    char str[1024];

    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    //build_ac
    build_AC(root, cnt);  //cnt　建立　队列的大小
    scanf("%s", str);
    //match_ac
    printf("match word cnnt = %d\n", match(root, str));

    
    
    return 0;
}
