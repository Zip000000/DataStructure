/*************************************************************************
	> File Name: h2.BiTrie.h
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月26日 星期一 14时28分43秒
 ************************************************************************/

#ifndef _H2BITRIE_H
#define _H2BITRIE_H
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "h1.Haffman.h"

#define MAX_NODE 256

int trienodecnt;

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
typedef struct DATrie {
    int *base, *check, *fail;
    int root, size;
} DATrie;

Code * get_Huffman_Codes();
DAHuffmanTrie *get_Huffman_Trans();
void check_file(const char *codefile, const char *transfile, const char *keywordsCodesFile);
KeyWords *get_key_words(const char *filename);
char *get_word_code(unsigned char *word, Code *huffCodes);

TrieNode *get_trie(Code *huffCodes, KeyWords *keywords);

DATrie *get_DATrie(int n);
int getBaseVal(TrieNode *root, DATrie *datrie);
void build_DATrie(int ind, TrieNode *root, DATrie *datrie);
void write_down_keywords_trie(DATrie *datrie, const char *filename);

#endif

