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

typedef struct Trie {
    int flag;
    struct Trie *l, *r;
} Trie;
/*
typedef struct Code {
    unsigned char *code;
} Code;
*/
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
    printf("%d\n", MAX_DAHUFF);
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

void check_file(const char *codefile, const char *transfile) {
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
}

int main() {
    check_file(Codes_File, Trans_File);
    Code *huffCodes = get_Huffman_Codes();
    printf("get_Huffman_Codes success!\n");
    
    DAHuffmanTrie *HuffTrie = get_Huffman_Trans();
    printf("get_Huffman_Trans success!\n");
    
    
    
    return 0;
}


