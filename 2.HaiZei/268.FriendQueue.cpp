/*************************************************************************
	> File Name: 268.FriendQueue.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月23日 星期二 15时20分41秒
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
#define MAX 1000000
typedef struct fri_part{
    int *q;
    int head, tail;
    int where;
} fri_part;
fri_part **fri;
int people[MAX + 5];
int final_friend[1005];
int q[MAX + 5], head = 0, tail = 0;

int push(int in) {
    //printf("push\n");
    if (people[in] == 0) {
        q[tail++] = in;
    } else {
        int qnum = people[in];
        if (fri[qnum]->where == -1) {
            fri[qnum]->where = tail;
            q[tail++] = 0-qnum;
            fri[qnum]->q[(fri[qnum]->tail)++] = in;
        } else {
            fri[qnum]->q[(fri[qnum]->tail)++] = in;
        }
    }
}
int pop() {
    if (q[head] < 0) {
        int qnum = 0-q[head];
        printf("%d\n", fri[qnum]->q[(fri[qnum]->head)++]);
        if(fri[qnum]->tail == fri[qnum]->head) {
            fri[qnum]->where = -1;
            head++;
        }
    } else {
        printf("%d\n", q[head++]);
        //printf("%d in real q \n", q[head++]);
        //printf("head = %d  tail = %d\n", head, tail);
    }
}

fri_part **fri_init(int n, int m) {
    fri_part **fri = (fri_part **)malloc(sizeof(fri_part *) * (n + 5));
    for (int i = 0; i <= n; i++) {
        fri[i] = (fri_part *)malloc(sizeof(fri_part));
        fri[i]->q = (int *)malloc(sizeof(int) * (m + 5));
        fri[i]->head = fri[i]->tail = 0;
        fri[i]->where = -1;
    }
    return fri;
}

int main() {
    memset(final_friend, 1, sizeof(final_friend));
    int n;
    int m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            int tmp_num;
            scanf("%d", &tmp_num);
            people[tmp_num] = i;
        }
    }
    fri = fri_init(n, m);
    char op[50];
    while (scanf("%s", op) != EOF) {
        if(op[0] == 'S') break;
        if (op[0] == 'E') {
            int in;
            scanf("%d", &in);
            push(in);
        } else {
            pop();
        }
    }
    
    return 0;
}



/*
void fri_push(int qnum, int  in) {
    //printf("fri_push\n");
    if (fri[qnum]->where == -1) {
        fri[qnum]->where = tail;
        q[tail++] = 0-qnum;
        fri[qnum]->q[(fri[qnum]->tail)++] = in;
    } else {
        fri[qnum]->q[(fri[qnum]->tail)++] = in;
    }
}
*/
/*
void fri_pop(int qnum) {
    qnum = 0-qnum;
    printf("%d\n", fri[qnum]->q[(fri[qnum]->head)++]);
    if(fri[qnum]->tail == fri[qnum]->head) {
        fri[qnum]->where = -1;
        head++;
    }
}
*/
/*
void q_push(int in) {
    //printf("q_push\n");
    q[tail++] = in;
}
void fri_realpush(int qnum, int in) {
    //printf("fri_realpush\n");
    fri[qnum]->q[(fri[qnum]->tail)++] = in;
}
*/
