/*************************************************************************
	> File Name: 3.AC.c
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月26日 星期一 14时27分52秒
 ************************************************************************/

#include<stdio.h>
#include "h2.BiTrie.h"

DATrie *get_datrie(const char *filename) {
    FILE *fp = fopen(filename, "r");
    int size, root;
    fscanf(fp, "%d %d", &size, &root);
    DATrie *datrie = (DATrie *)calloc(1, sizeof(DATrie));
    datrie->base = (int *)calloc(size, sizeof(int));
    datrie->check = (int *)calloc(size, sizeof(int));
    datrie->fail = (int *)calloc(size, sizeof(int));
    datrie->size = size;
    datrie->root = root;
    int i, base, check, fail;
    while (~fscanf(fp, "%d %d %d %d", &i, &base, &check, &fail)) {
        datrie->base[i] = base;
        datrie->check[i] = check;
        datrie->fail[i] = fail;
        //if (i < 100) printf("%d %d %d %d\n", i, base, check, fail);
    }
    return datrie;
}

void filecheck(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("缺少关键字字典文件Key_Words_DATrie\n");
        exit(1);
    }
    fclose(fp);
}

#define no_this_child(datrie, ind, i) (abs(datrie->check[datrie->base[ind] + i]) != ind)

void search_ac(Code *huffCodes, DAHuffmanTrie *HuffTrie, DATrie *keytrie) {
    unsigned char ch;
    int p = keytrie->root;
    while (~scanf("%c", &ch)) {
        //printf("ch = %d\n", ch);
        if (ch == 10 || ch == 32) continue;
        if (ch == 0) break;
        for (int i = 0; huffCodes[ch].code[i]; i++) {
            //printf("i = %d strlen = %ld\n", i, strlen(huffCodes[ch].code));
            int c = huffCodes[ch].code[i] - '0';
            //printf("%d", c);
            while (p && no_this_child(keytrie, p, c)) p = keytrie->fail[p];
            if (p == 0) p = keytrie->root;
            else p = keytrie->base[p] + c;
            int q = p;
            while (q) {
                if (keytrie->check[q] < 0) {
                    printf("\n找到了一个词！！！\n");
                    //printf("\nq = %d checkq = %d fileq = %d\n", q, keytrie->check[q], keytrie->fail[q]);
                }
                q = keytrie->fail[q];
            }
        }
    }
}

int main() {
    filecheck(Key_Words_DATrie);
    DATrie *keytrie = get_datrie(Key_Words_DATrie);
    printf("get_datrie success!\n");
    
    Code *huffCodes = get_Huffman_Codes();
    printf("get_Huffman_Codes success!\n");
    
    DAHuffmanTrie *HuffTrie = get_Huffman_Trans();
    printf("get_Huffman_Trans success!\n");
   
    search_ac(huffCodes, HuffTrie, keytrie);

    return 0;
}


/*
    printf("%d %d\n", keytrie->size, keytrie->root);
    for (int i = 0; i < 100; i++) {
        printf("%d %d %d\n", i, keytrie->base[i], keytrie->check[i]);
    }
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
         HuffTrie->base = (int *)calloc(MAX_DAHUFF, sizeof(int));
         HuffTrie->check = (int *)calloc(MAX_DAHUFF, sizeof(int));
         HuffTrie->data = (unsigned char *)calloc(MAX_DAHUFF, sizeof(unsigned char));
         FILE *fp = fopen(Trans_File, "r");
         int base, check, i;
         unsigned char data;
     while (~fscanf(fp, "%d %d %d %hhu\n", &i, &base, &check, &data)) {
                 //printf("fscanf 1\n");
         //        //printf("%d %d %d %d\n", i, base, check, data);
         //                HuffTrie->base[i] = base;
         //                        HuffTrie->check[i] = check;
         //                                HuffTrie->data[i] = data;
         //                                    
     }
         fclose(fp);
         return HuffTrie;

 }


