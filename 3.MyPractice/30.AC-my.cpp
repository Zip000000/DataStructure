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
    Node *p = (Node *)malloc(sizeof(Node));
    return p;
}

int insert(Node *root, char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BASE_LETTER;
        if (p->next[ind] == NULL) cnt++, p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}

void build_ac(Node *root) {
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *now_node = q.front();
        for (int i = 0; i < BASE; i++) {
            if (now_node->next[i] == NULL) continue;
            Node *nf = now_node->fail;
            while (nf && nf->next[i] == NULL) nf = nf->fail;
            if (nf == NULL) now_node->next[i]->fail = root;
            else now_node->next[i]->fail = nf->next[i];
            q.push(now_node->next[i]);
        }
        q.pop();
    }
}

int match(Node *root, const char *str) {
    Node *p = root;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BASE_LETTER;
        while (p && p->next[ind] == NULL) p = p->fail;
        if (p == NULL) p = root;
        else p = p->next[ind];
        Node *q = p;
        while (q) cnt += q->flag, q = q->fail;
    }
    return cnt;
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
    
    printf("after insert\n");
    //build_ac 建立失败指针（已经有了字典树了）
    build_ac(root);
    printf("afterbuild\n");
    scanf("%s", str);
    printf("match word cnt = %d\n", match(root, str));
    

    
    
    
    return 0;
}
