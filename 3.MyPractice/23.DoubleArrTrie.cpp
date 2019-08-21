/*************************************************************************
	> File Name: 22.trie.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月20日 星期二 13时15分43秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

#define BASE 26
#define BASE_LETTER 'a'

#define CODE(i) (str[i] - BASE_LETTER)
int cnt;

typedef struct Node {
    int flag;
    Node *next[BASE];
} Node;

typedef struct DANode {
    int base;
    int check;
} DANode;

Node *getNewNode() {
    cnt++;
    Node *n = (Node *)calloc(sizeof(Node), 1);
    return n;
}

DANode *getDANode(int n) {
    DANode *arr = (DANode *)calloc(n, sizeof(DANode));
    return arr;
}

void insert(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[CODE(i)] == NULL) p->next[CODE(i)] = getNewNode();
        p = p->next[CODE(i)];
    }
    p->flag = 1;
    return ;
}

int query(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p == NULL) return 0;
        p = p->next[CODE(i)];
    }
    return p->flag;
}

void output(Node *root, int k, char *buff) {
    if (root == NULL) return;
    if (root->flag == 1) cout << buff << endl;
    
    for (int i = 0; i < BASE; i++) {
        buff[k] = i + BASE_LETTER;
        buff[k + 1] = '\0';
        output(root->next[i], k + 1, buff);
    }
}


void clear(Node *root) {
    if (root == NULL) return;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int getBaseValue(Node *root, DANode *darr) {
    int base = 2;
    while (1) {
        int flag = 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (darr[base + i].check == 0) continue;
            flag = 0;
            break;
        }
        if (flag) return base;
        base += 1;
    }
    return base;
}

void trans_trie_to_double_array(Node *root, int ind, DANode *darr) {
    darr[ind].base = getBaseValue(root, darr);
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        darr[darr[ind].base + i].check = ind * (root->next[i]->flag ? -1 : 1);
    }

    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        trans_trie_to_double_array(root->next[i], darr[ind].base + i, darr);
    }
    return;
}

int output_double_array(int ind, int k, DANode *darr, char *buff) {
    if (darr[ind].check < 0) cout << buff << endl;

    for (int i = 0; i < BASE; i++) {
        if (abs(darr[darr[ind].base + i].check) - ind) continue;
        buff[k] = BASE_LETTER + i;
        buff[k + 1] = '\0';
        output_double_array(darr[ind].base + i, k + 1, darr, buff);
    }
    return 0;
}

int main() {
    char str[1000]; 
    int n;
    cin >> n;
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    cout << "cnt = " << cnt << endl;
    DANode *darr = getDANode(cnt * 26 + 100);
    printf("before trans_trie_to_double_array\n");
    trans_trie_to_double_array(root, 1, darr);
    printf("after trans_trie_to_double_array\n");

    cout << "---------------------------------" << endl;
    output(root, 0, str);
    cout << "---------------------------------" << endl;
    cout << "---------------------------------" << endl;
    output_double_array(1, 0, darr, str);
    cout << "---------------------------------" << endl;
    while (~scanf("%s", str)) {
        printf("query %s ret = %s\n", str, query(root, str) ? "YES" : "NO");
    }


    return 0;
}
