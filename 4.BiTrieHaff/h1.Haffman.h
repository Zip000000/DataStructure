/*************************************************************************
	> File Name: h1.Haffman.h
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月25日 星期日 20时34分08秒
 ************************************************************************/

#ifndef _H1HAFFMAN_H
#define _H1HAFFMAN_H
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_N 100
#define MAX_LEN 1024
#define MAX_NODE 256
#define BASE 2
#define MAX_DAHUFF ((MAX_NODE * BASE) + 100)
#define Codes_File "./Codes_Huffman"
#define Trans_File "./Trans_Haffman"
#define Key_Words_File "./Key_Words"
#define Key_Words_DATrie "./KeywordsCodes"



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

typedef struct DAHuffmanTrie {
    int *base, *check;
    int root, size;
    unsigned char *data;
} DAHuffmanTrie;

Node *getNewNode();

void outputNodes(Node **nodes);
Node **get_words_frequency();

Node *getCombineNode(Node *node1, Node *node2);
HaffmanTree *getNewTree();

void insertOnce(Node**nodes, int i);
void extractCode(Node *root, Code *codes, int k, char *buff);
HaffmanTree *build(Node **nodes);

DAHuffmanTrie *get_DAHuffmanTrie(int n);

int getBaseValue(Node *root, DAHuffmanTrie *trie);
int is_leaf(Node *root);

void build_DAHuffmanTrie(int ind, Node *root, DAHuffmanTrie *trie);
void check_codesfile(const char *codesfile, const char *solvefile);
void write_down_Haffman_codes(Code *codes, const char *codesfile);

void write_down_Haffman_Solve_DATrie(DAHuffmanTrie *DAHuff, const char *filename);

#endif
