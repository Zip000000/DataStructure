/*************************************************************************
	> File Name: Haffman.c
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月24日 星期六 16时09分21秒
 ************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_LEN 1024
#define MAX_NODE 256

#define swap(a,  b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}

typedef struct Words {
    unsigned char *str;
} Words;

typedef struct ALLWords {
    Words word[MAX_N + 5];
    int n;
} ALLWords;
ALLWords allwords;

typedef struct Node {
    unsigned char ch;
    int p;
    struct Node *l, *r;
} Node;
Node *nodes[MAX_NODE + 5];
int nodecnt = 0;

typedef struct Code {
    unsigned char ch;
    unsigned char *code;
} Code;

typedef struct HaffmanTree {
    Node *root;
    int n;
    Code *codes;
} HaffmanTree;

int get_all_words(Words *word) {
    unsigned char buff[MAX_LEN + 5];
    int cnt = 0;
    while (~scanf("%s", buff)) word[cnt++].str = strdup(buff);
    return cnt;
}

Node *getNewNode() {
    Node *n = (Node *)malloc(sizeof(Node));
    return n;
}

void get_words_frequency(ALLWords *all, Node **nodes) {
    int n = all->n;
    for (int i = 0; i < n; i++) {
        unsigned char *s = all->word[i].str;
        for (int j = 0; s[j]; j++) {
            if (nodes[s[j]] == NULL) {
                nodes[s[j]] = getNewNode();
                nodes[s[j]]->ch = s[j];
                nodecnt++;
            } 
            nodes[s[j]]->p += 1;
        }
    }
}

Node *getCombineNode(Node *node1, Node *node2) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->p = node1->p + node2->p;
    n->l = node1;
    n->r = node2;
    return n;
}
HaffmanTree *getNewTree() {
    HaffmanTree *t = (HaffmanTree *)malloc(sizeof(HaffmanTree));
    t->codes = (Code *)malloc(sizeof(Code) * MAX_NODE);
    t->root = NULL;
    return t;
}

HaffmanTree *build(Node **nodes) {
    HaffmanTree *tree = getNewTree();
    for (int i = 1; i < MAX_NODE; i++) {
        for (int j = i; j >= 1; j--) {
            if (nodes[j] == NULL) {
                continue;
            } else if (nodes[j - 1] == NULL) {
                swap(nodes[j], nodes[j - 1]);
                continue;
            } else {
                if (nodes[j]->p <= nodes[j - 1]->p) break;
                swap(nodes[j], nodes[j - 1]);
            }
        }
    }
    /*
    for (int i = 0; nodes[i]; i++) {
        printf("%d : %c : p = %d\n", i, nodes[i]->ch, nodes[i]->p);
    }
    */
    for (int i = nodecnt - 1; i >= 1; --i) {
        Node *n = getCombineNode(nodes[i], nodes[i - 1]);
        nodes[i - 1] = n;
        for (int j = i - 1; j >= 1; --j) {
            if (nodes[j]->p <= nodes[j - 1]->p) break;
            swap(nodes[j], nodes[j - 1]);
        }
    }
    tree->root = nodes[0];
    tree->n = nodecnt;
    free(nodes);
    return tree;
}

int main() {
    allwords.n = get_all_words(allwords.word);
    printf("after get all words\n");
    get_words_frequency(&allwords, nodes);
    printf("after get_word_frequency\n");
    
    HaffmanTree *tree = build(nodes);

    extractCode(tree,)

    return 0;
}







/*
    for (int i = 0; i < cnt; i++) {
        printf(" %d : %s\n", i, word[i].str);
    }
  */  
    
    
    
    /*
    for (int i = 0; i < MAX_NODE; i++) {
        printf("%d : p = %d\n", node[i].ch, node[i].p);
    }


    for (int i = 0; i < MAX_NODE; i++) {
        printf("%d %c : %d\n", i, nodes[i].ch, nodes[i].p);
    }
    printf(" num = %d\n", nodecnt);
    */
