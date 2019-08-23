/*************************************************************************
	> File Name: 4.AC.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月22日 星期四 10时39分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define BASE 26
#define BEGIN_LETTER 'a'
typedef struct Node {
    int flag;
    struct Node *next[BASE], *fail;
} Node ;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; i < BASE; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(), cnt++;
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *root) {
    if (root == NULL) return;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    
}

typedef struct Queue {
    Node **data;
    int head, tail, size;
} Queue;

Queue *init_queue(int n) {
    Queue *q = (Queue*)calloc(sizeof(Queue), 1);
    q->data = (Node **)malloc(sizeof(Node *) * n);
    q->head = q->tail = 0;
    return q;
}

Node *front(Queue *q) { return q->data[q->head]; }

int empty(Queue *q) {
    return q->head == q->tail;
}

void push(Queue *q, Node *node) {
    q->data[q->tail++] = node;
    return;
}

void pop(Queue *q) {
    if (empty(q)) return;
    q->head--;
}

void clear_queue(Queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
}

void build_ac(Node *root, int n) {
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
            if (p == NULL) now_node->next[i] = root;
            else now_node->next[i]->fail = p->next[i];
            push(q, now_node->next[i]);
        }
    }
}

int main() {
    Node *root = getNewNode();

    int n, cnt = 0;
    char str[1000];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    //build ac

    scanf("%s", str);
    
    return 0;
}
