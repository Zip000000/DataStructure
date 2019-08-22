/*************************************************************************
	> File Name: 281.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月21日 星期三 16时09分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

#define BASE 26
#define MAX_N 1000000
#define BASE_LETTER 'a'
using namespace std;

struct Node {
    int flag;
    int next[BASE];
} Node[MAX_N + 5];

int cnt = 1, root = 1;
inline int getNewNode() { return ++cnt; }

void insert(char *str) {
    int p = root;
    
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BASE_LETTER;
        if (Node[p].next[ind] == 0) Node[p].next[ind] = getNewNode();
        p = Node[p].next[ind];
    }
    Node[p].flag += 1;
    return ;
}

int query(char *str) {
    int p = root;
    int cnt = 0;
    for (int i = 0; i < str[i]; i++) {
        int ind = str[i] - BASE_LETTER;
        if (Node[p].next[ind] == 0) break;
        p = Node[p].next[ind];
        cnt += Node[p].flag;
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    char str[MAX_N + 5] = {0};
    for (int i = 0; i < n; i++) {
        cin >> str;
        insert(str);
    }

    for (int i = 0; i < m; i++) {
        cin >> str;
        int ans = query(str);
        cout << ans << endl;
    }
    
    return 0;
}
