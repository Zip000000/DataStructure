/*************************************************************************
	> File Name: Haffman.c
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月24日 星期六 16时09分21秒
 ************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_N 100
#define MAX_LEN 1024
#define MAX_NODE 256
#define BASE 2

#define swap(a,  b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}
/*
typedef struct Words {
    unsigned char *str;
} Words;

typedef struct ALLWords {
    Words word[MAX_N + 5];
    int n;
} ALLWords;
ALLWords allwords;
*/
typedef struct Node {
    unsigned char ch;
    int p;
    struct Node *next[2];
} Node;
Node *nodes[MAX_NODE + 5];

typedef struct Code {
    unsigned char ch;
    unsigned char *code;
} Code;

typedef struct HaffmanTree {
    int n;
    Node *root;
    Code *codes;
} HaffmanTree;
/*
int get_all_words(Words *word) {
    unsigned char buff[MAX_LEN + 5];
    int cnt = 0;
    while (~scanf("%s", buff)) word[cnt++].str = strdup(buff);
    return cnt;
}
*/

Node *getNewNode() {
    Node *n = (Node *)malloc(sizeof(Node));
    n->ch = 0;
    n->p = 0;
    n->next[0] = n->next[1] = NULL;
    return n;
}

void outputNodes(Node **nodes) {
    for (int i = 0; i < MAX_NODE; i++) {
        if (nodes[i] == NULL) continue;
        printf("%d : ch = %d : p = %d \n", i, nodes[i]->ch, nodes[i]->p);
    }
}

Node **get_words_frequency() {
    Node **nodes = (Node **)malloc(sizeof(Node *) * (MAX_NODE + 5));
    unsigned char ch;
    while (~scanf("%c", &ch)) {
        if (nodes[ch] == NULL) nodes[ch] = getNewNode();
        nodes[ch]->ch = ch;
        nodes[ch]->p += 1;
    }
    for (int i = 0; i < MAX_NODE; i++) {
        if (nodes[i] != NULL) continue;
        nodes[i] = getNewNode();
        nodes[i]->ch = i;
    }
    outputNodes(nodes);
    return nodes;
}

Node *getCombineNode(Node *node1, Node *node2) {
    Node *n = getNewNode();
    n->p = node1->p + node2->p;
    n->next[0] = node1;
    n->next[1] = node2;
    return n;
}
HaffmanTree *getNewTree() {
    HaffmanTree *t = (HaffmanTree *)malloc(sizeof(HaffmanTree));
    t->codes = (Code *)malloc(sizeof(Code) * MAX_NODE);
    t->root = NULL;
    return t;
}

void insertOnce(Node**nodes, int i) {
    for (int j = i; j >= 1; j--) {
        if (nodes[j]->p <= nodes[j - 1]->p) continue;
        swap(nodes[j], nodes[j - 1]);
    }
}
void extractCode(Node *root, Code *codes, int k, char *buff) {
    buff[k] = '\0';
    if (root->next[0] == NULL && root->next[1] == NULL) {
        codes[root->ch].ch = root->ch;
        codes[root->ch].code = strdup(buff);
        printf("ch = %d code : %s\n", codes[root->ch].ch, codes[root->ch].code);
        return ;
    }
    buff[k] = '0';
    extractCode(root->next[0], codes, k + 1, buff);
    buff[k] = '1';
    extractCode(root->next[1], codes, k + 1, buff);
    return;
}
HaffmanTree *build(Node **nodes) {
    HaffmanTree *tree = getNewTree();
    for (int i = 1; i < MAX_NODE; i++) {
        insertOnce(nodes, i);
    }
    printf("after sort\n");
    outputNodes(nodes);
    /*
    for (int i = 0; nodes[i]; i++) {
        printf("%d : %c : p = %d\n", i, nodes[i]->ch, nodes[i]->p);
    }
    */
    for (int i = MAX_NODE - 1; i >= 1; --i) {
        Node *new_node = getCombineNode(nodes[i], nodes[i - 1]);
        nodes[i - 1] = new_node;
        insertOnce(nodes, i - 1);
    }
    tree->root = nodes[0];
    tree->n = MAX_NODE;
    char *buff = (char *)calloc(sizeof(char), MAX_NODE);
    extractCode(tree->root, tree->codes, 0, buff);
    printf("after extract Code\n");
    free(nodes);
    return tree;
}
typedef struct DAHuffmanTrie {
    int *base, *check;
    int root, size;
    unsigned char *data;
} DAHuffmanTrie;

DAHuffmanTrie *get_DAHuffmanTrie(int n) {
    DAHuffmanTrie *trie = (DAHuffmanTrie *)calloc(sizeof(DAHuffmanTrie), 1);
    trie->root = 1;
    trie->size = n;
    trie->base = (int *)calloc(sizeof(int), n);
    trie->check = (int *)calloc(sizeof(int), n);
    trie->data = (unsigned char *)calloc(sizeof(unsigned char), n);
    trie->check[trie->root] = -1;
    return trie;
}

int getBaseValue(Node *root, DAHuffmanTrie *trie) {
    int base = 2, flag = 0;
    while (1) {
        int flag = 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (trie->check[base + i] == 0) continue;
            flag = 0;
            break;
        }
        if (flag) break;
        base += 1;
    }
    return base;

}
int is_leaf(Node *root) {
    return (root->next[0] == NULL && root->next[1] == NULL);
}

void build_DAHuffmanTrie(int ind, Node *root, DAHuffmanTrie *trie) {
    int basenum = trie->base[ind] = getBaseValue(root, trie);
    
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int child = basenum + i;
        trie->check[basenum + i] = (is_leaf(root->next[i]) ? -ind : ind);
        trie->data[basenum + i] = root->next[i]->ch;
    }

    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        build_DAHuffmanTrie(basenum + i, root->next[i], trie);
    }
    return ;
}

void check_codesfile(const char *codesfile, const char *solvefile) {
    FILE *fp = fopen(codesfile, "r");
    if (fp != NULL) {
        printf("Codes文件已存在\n"); 
        fclose(fp); 
        exit(1);
    }
    fp = fopen(codesfile, "r");
    if (fp != NULL) {
        printf("Codes文件已存在\n"); 
        fclose(fp); 
        exit(1);
    }
    printf("开始获得当前环境下的字符最优编码......\n");
}

void write_down_Haffman_codes(Code *codes, const char *codesfile) {
    FILE *fp = fopen(codesfile, "w");
    if (fp == NULL) { perror("fopen in write_down_Haffman_codes"); exit(1); }
    for (int i = 0; i < MAX_NODE; i++) {
        fprintf(fp, "%d %s\n", codes[i].ch, codes[i].code);
    }
    fclose(fp);
    return ;
}

void write_down_Haffman_Solve_DATrie(DAHuffmanTrie *DAHuff, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) { perror("fopen in write_down_Haffman_codes"); exit(1); }
    for (int i = 0; i < MAX_NODE; i++) {
        fprintf(fp, "%d %d %d\n", DAHuff->base[i], DAHuff->check[i], DAHuff->data[i]);
    }
    fclose(fp);
    return ;
}

int main() {
    char codesfile[100] = "./Codes_Huffman";
    char transfile[100] = "./Trans_Haffman";
    check_codesfile(codesfile, transfile);
    Node **nodes = get_words_frequency();
    printf("词频统计完毕\n");
    
    HaffmanTree *tree = build(nodes);
    printf("Huffman树建立完毕\n");

    write_down_Haffman_codes(tree->codes, codesfile);
    printf("编码文件 [Codes] 生成完毕\n");

    DAHuffmanTrie *DAHuff = get_DAHuffmanTrie(tree->n * BASE + 100);
    build_DAHuffmanTrie(DAHuff->root, tree->root, DAHuff);
    printf("双数组Huffman字典树　生成完毕\n");
    
    write_down_Haffman_Solve_DATrie(DAHuff, transfile);
    printf("译码文件 [Trans] 生成完毕\n");
    
    return 0;
}





    /*
    for (int i = 0; i < DAHuff->size; i++) {
        printf("base[%d] = %d check[%d] = %d data = %d\n", i, DAHuff->base[i], i, DAHuff->check[i], DAHuff->data[i]);
    }
    for (int j = i; j >= 1; j--) {
        if (nodes[j] == NULL) {
            break;
        } else if (nodes[j - 1] == NULL || nodes[j]->p > nodes[j - 1]->p) {
            swap(nodes[j], nodes[j - 1]);
            continue;
        }
        break;
    }
    */
