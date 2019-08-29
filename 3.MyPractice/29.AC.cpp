/*************************************************************************
	> File Name: 29.AC.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月29日 星期四 15时02分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
#define BASE 26
#define BASE_LETTER 'a'
typedef struct Node {
    int flag;
    struct Node *next[BASE], *fail;
} Node;

Node *getNewNode() {
    Node *p = (Node *)calloc(1, sizeof(Node));
    return p;
}

int insert(Node *root, char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BASE_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(), cnt++;
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}

void build_ac(Node *root) {
    queue<Node *> q;
    root->fail = NULL;
    q.push(root);
    while (!q.empty()) {
        Node *now_node = q.front();
        q.pop();
        //建立失败指针
        //每轮都是为 当前节点的孩子们 建立失败指针 (利用当前节点的失败指针)，类似KMP
        for (int i = 0; i < BASE; i++) {
            if (now_node->next[i] == NULL) continue;
            Node *p = now_node->fail;
            while (p && p->next[i] == NULL) p = p->fail;
            if (p == NULL) now_node->next[i]->fail = root;
            else now_node->next[i]->fail = p->next[i];
            q.push(now_node->next[i]);
        }
        //建立完毕
    }
    return ;
}

int match(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    //q一直都在 下面数第一个可能的 fail指针处

    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BASE_LETTER;
        while (p && p->next[ind] == NULL) p = p->fail;
        if (p == NULL) p = root;
        else p = p->next[ind];
        Node *q = p;
        while (q) cnt += q->flag, q = q->fail; 
    }
    return cnt;
/*
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BASE_LETTER;
        while (p && p->next[ind] == NULL) p = p->fail;
        if (p == NULL) p = root;
        else p = p->next[ind];
        Node *q = p;
        while (q != NULL) cnt += q->flag, q = q->fail;
    }
    return cnt;
    */
}


void clear(Node *node) {
    if (node == NULL) return;
    for (int i = 0; i < BASE; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int main() {
    Node *root = getNewNode();
    int n, cnt;
    scanf("%d", &n);
    int op;
    char str[1000];

    for (int i = 0; i < n; i++) {
        scanf("%s",str);
        cnt += insert(root, str);
    }
    
    //build_ac 建立失败指针（已经有了字典树了）
    build_ac(root);
    scanf("%s", str);
    printf("match word cnt = %d\n", match(root, str));
    

    
    
    
    return 0;
}
