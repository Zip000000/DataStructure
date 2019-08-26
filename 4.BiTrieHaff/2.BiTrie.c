/*************************************************************************
	> File Name: 2.BiTrie.c
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月25日 星期日 15时56分40秒
 ************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "h1.Haffman.h"

#define MAX_NODE 256

typedef struct Words {
    unsigned char *word;
} Words;
typedef struct KeyWords {
    int size, cnt;
    Words *wordslist;
} KeyWords;

typedef struct TrieNode {
    int flag;
    struct TrieNode *next[BASE];
} TrieNode;
int trienodecnt;
typedef struct DATrie {
    int *base, *check, *fail;
    int root, size;
} DATrie;


Code * get_Huffman_Codes() {
    Code *huffCodes = (Code *)malloc(sizeof(Code) * MAX_NODE);
    FILE *fp = fopen(Codes_File, "r");
    int tmp;
    char buff[MAX_NODE + 5];

    while (~fscanf(fp, "%d %s", &tmp, buff)) {
        huffCodes[tmp].code = strdup(buff);
    }
    fclose(fp);
    return huffCodes;
}

DAHuffmanTrie *get_Huffman_Trans() {
    DAHuffmanTrie *HuffTrie = (DAHuffmanTrie *)malloc(sizeof(DAHuffmanTrie));
    HuffTrie->root = 1;
    HuffTrie->base = (int *)calloc(MAX_DAHUFF, sizeof(int));
    HuffTrie->check = (int *)calloc(MAX_DAHUFF, sizeof(int));
    HuffTrie->data = (unsigned char *)calloc(MAX_DAHUFF, sizeof(unsigned char));
    FILE *fp = fopen(Trans_File, "r");
    int base, check, i;
    unsigned char data;
    while (~fscanf(fp, "%d %d %d %hhu\n", &i, &base, &check, &data)) {
        //printf("fscanf 1\n");
        //printf("%d %d %d %d\n", i, base, check, data);
        HuffTrie->base[i] = base;
        HuffTrie->check[i] = check;
        HuffTrie->data[i] = data;
    }
    fclose(fp);
    return HuffTrie;
}

void check_file(const char *codefile, const char *transfile, const char *keywordsCodesFile) {
    FILE *fp = fopen(codefile, "r");
    if (fp == NULL) {
        printf("缺少编码文件[Codes_Huffman]\n");
        exit(1);
    }
    fclose(fp);
    fp = fopen(transfile, "r");
    if (fp == NULL) {
        printf("缺少译码文件[Trans_Huffman]\n");
        exit(1);
    }
    fclose(fp);
    fp = fopen(keywordsCodesFile, "r");
    if (fp != NULL) {
        printf("关键词文件已存在[KeywordsCodes]\n");
        fclose(fp);
        exit(1);
    }
}
KeyWords *get_key_words(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char buff[1024];
    KeyWords *k = (KeyWords *)calloc(1, sizeof(KeyWords));
    k->size = 2, k->cnt = 0;
    k->wordslist = (Words *)calloc(k->size, sizeof(Words));
    while (~fscanf(fp, "%s", buff)) {
        if (k->cnt == k->size) {
            k->size *= 2;
            k->wordslist = (Words *)realloc(k->wordslist, k->size * sizeof(Words));
        }
        k->wordslist[(k->cnt)++].word = (unsigned char *)strdup(buff);
    }
    for (int i = 0; i < k->cnt; i++) {
        printf("%d : %s\n", i, k->wordslist[i].word);
    }
    return k;
}
char *get_word_code(unsigned char *word, Code *huffCodes) {
    char *buff = (char *)calloc(MAX_NODE * strlen(word) + 5, sizeof(char));
    for (int i = 0; word[i]; i++) {
        int ind = word[i];
        strcat(buff, huffCodes[ind].code);
    }
    //printf("len = %ld  code : %s\n",strlen(buff), buff);
    return buff;
}

TrieNode *getNewTrieNode() {
    TrieNode *node = (TrieNode *)calloc(1, sizeof(TrieNode));
    return node;
}

TrieNode *get_trie(Code *huffCodes, KeyWords *keywords) {
    TrieNode *root = getNewTrieNode();
    for (int i = 0; i < keywords->cnt; i++) {
        TrieNode *p = root;
        printf("%s:\n", keywords->wordslist[i].word);
        char *code = get_word_code(keywords->wordslist[i].word, huffCodes);
        printf("%s\n", code);
        for (int j = 0; code[j]; j++) {
            int ind = code[j] - '0';
            printf("%d", ind);
            if (p->next[ind] == NULL) p->next[ind] = getNewTrieNode(), trienodecnt += 1;
            p = p->next[ind];
        }
        printf("\n");
        p->flag = 1;
        free(code);
    }
    return root;
}

DATrie *get_DATrie(int n) {
    DATrie *trie = (DATrie *)calloc(1, sizeof(DATrie));
    trie->root = 1;
    trie->size = n;
    trie->base = (int *)calloc(n, sizeof(int));
    trie->check = (int *)calloc(n, sizeof(int));
    trie->fail = (int *)calloc(n, sizeof(int));
    trie->check[trie->root] = 0;
    return trie;
}

int getBaseVal(TrieNode *root, DATrie *datrie) {
    int base = 1, flag = 1;
    while (flag) {
        base += 1;
        flag = 0;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (datrie->check[base + i] == 0) continue;
            //printf("in getBASEVAL base = %d BSE = %d\n", base, BASE);
            flag = 1;
            break;
        }
    }
    return base;
}

void build_DATrie(int ind, TrieNode *root, DATrie *datrie) {
    datrie->base[ind] = getBaseVal(root, datrie);
    int base = datrie->base[ind];
    //printf("base = %d\n", base);
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int child = base + i;
        datrie->check[child] = ind * (root->next[i]->flag ? -1 : 1);
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        build_DATrie(base + i, root->next[i], datrie);
    }
    return ;
}
void write_down_keywords_trie(DATrie *datrie, const char *filename) {
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%d %d\n", datrie->size, datrie->root);
    for (int i = 0; i < datrie->size; i++) {
        fprintf(fp, "%d %d %d %d\n", i, datrie->base[i], datrie->check[i], datrie->fail[i]);
    }
    fclose(fp);
}

void build_AC(DATrie *datrie) {
    int *queue = (int *)malloc(sizeof(int) * datrie->size);
    int head = 0, tail = 0;
    datrie->fail[datrie->root] = 0;
    queue[tail++] = datrie->root;
    while (head < tail) {
        int now = queue[head++];
        for (int i = 0; i < BASE; i++) {
            int child = datrie->base[now] + i;
            if (abs(datrie->check[child]) != now) continue;
            int p = datrie->fail[now];
            while (p && abs(datrie->check[child]) != p) p = datrie->fail[p];
            if (p == 0) p = datrie->root;
            else p = datrie->base[p] + i;
            datrie->fail[child] = p;
            queue[tail++] = datrie->base[now] + i;
        }
    }
    return ;
}
/*
void query(TrieNode *root, Code *huffCodes) {
    unsigned char ch;
    TrieNode *p = root;
    while (~scanf("%c", &ch)) {
        printf("ch = %d\n", ch);
        if (ch == 10 || ch == 32) continue;
        unsigned char *code = huffCodes[ch].code;
        for (int i = 0; code[i]; i++) {
            if (p == NULL) break;
            printf("codei = %d", code[i] - '0');
            p = p->next[code[i] - '0'];
            if (p && p->flag == 1) {
                printf("找到了！\n");
                p = root;
            } 
        }
        printf("\n");
    }
}

void query_DATrie(DATrie *datrie, Code *huffCodes) {
    unsigned char ch;
    int p = datrie->root;
    while (~scanf("%c", &ch)) {
        printf("ch = %d\n", ch);
        if (ch == 10 || ch == 32) continue;
        unsigned char *code = huffCodes[ch].code;
        for (int i = 0; code[i]; i++) {
            int ind = code[i] - '0';
            int child = datrie->base[p] + ind;
            if (abs(datrie->check[child]) != p) return;
            if (datrie->check[child] < 0) {printf("成一词\n");}
            p = child;
        }
        printf("\n");
    }
    
}
*/
int main() {
    check_file(Codes_File, Trans_File, Key_Words_DATrie);
    Code *huffCodes = get_Huffman_Codes();
    printf("get_Huffman_Codes success!\n");
    
    DAHuffmanTrie *HuffTrie = get_Huffman_Trans();
    printf("get_Huffman_Trans success!\n");
    
    KeyWords *keywords = get_key_words(Key_Words_File);
    
    TrieNode *trieroot = get_trie(huffCodes, keywords);
    printf("get Keywords Trie success!\n");
    
    DATrie *datrie = get_DATrie(trienodecnt * BASE + 100);
    printf("get DATrieroot success!\n");
    
    build_DATrie(datrie->root, trieroot, datrie);
    printf("build DATrie success!\n");

    build_AC(datrie);
    printf("build AC success\n");
    write_down_keywords_trie(datrie, Key_Words_DATrie);
    printf("OVER\n");
    //query(trieroot, huffCodes);
    //query_DATrie(datrie, huffCodes);
    return 0;
}

/*
    for (int i = 0; i < keywords->cnt; i++) {
        printf("%d : %s\n", i, keywords->wordslist[i].word);
    }
*/
