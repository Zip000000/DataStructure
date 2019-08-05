/*************************************************************************
	> File Name: 0.practice.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月17日 星期三 17时02分16秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
     char data;
     struct Node *l, *r;
} Node;

Node *get_new_node(char data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->l = n->r = NULL;
    return n;
}


void preOrder(Node *root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preOrder(root->l);
    preOrder(root->r);
}
Node* createTree(char *list, int n) {
    Node *root = NULL, *curr = NULL;
    Node **s = (Node **)malloc(sizeof(Node *) * n);
    int top = 0;
    s[top++] = curr;
    int flag = 0;
    #define LEFT 1
    #define RIGHT 2
    for (int i = 0; list[i] != '\0'; i++) {
        printf("i = %d\n", i);
        switch (list[i]) {
        case '(':
            s[top++] = curr;
            flag = LEFT;
            break;
        case ',':
            flag = RIGHT;
            break;
        case ')':
            top--;
            break;
        default:
            curr = get_new_node(list[i]);
            if (root == NULL) root = curr;
            if (flag == LEFT) s[top - 1]->l = curr;
            if (flag == RIGHT) s[top - 1]->r = curr;
        }
    }
    return root;
}
int main () {
    char list[] = "A(B(C,D),E(,F))";
    Node *root = createTree(list, 6);
    preOrder(root);    
    printf("\n");

    
     return 0;
 }





/*
    Node *root = NULL;
    Node *curr = NULL;
    Node *s[100];
    int top = 0;
    s[top++] = curr;
    int i = 0;
    #define LEFT 1
    #define RIGHT 2
    int flag = 0;
    while (list[i]) {
        printf("i = %d\n", i);
        switch (list[i]) {
            case '(':
                   s[top++] = curr;
                   flag |= LEFT;
                   break;
            case ',':
                   flag |= RIGHT;
                   break;
            case ')':
                   top--;
                   break;
            case ' ': 
                   break;
            default: 
                    curr = get_new_node(list[i]);
                    if (root == NULL) {
                        root = curr;
                    } else if (flag & LEFT) {
                        s[top - 1]->l = curr;
                    } else if (flag & RIGHT) {
                        s[top - 1]->r = curr;
                    }
                    flag = 0;
                    break;
        }
        preOrder(root);    
        printf("\n");
        i++;    
    }
    return root;

*/
