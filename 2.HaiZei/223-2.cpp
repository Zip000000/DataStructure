/*************************************************************************
	> File Name: 223-2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月28日 星期三 16时09分56秒
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
#define MAX_N 10000
#define lc(ind) (tree[ind].lind)
#define rc(ind) (tree[ind].rind)
#define sum(ind) (tree[ind].sum)
#define tag(ind) (tree[ind].tag)
#define cnt(ind) (tree[ind].cnt)
long long arr[MAX_N + 5];

struct Node {
    long long sum, tag, cnt;
    int lind, rind;
} tree[(MAX_N << 1) + 5];
int root = 0, cnt = 1;
int getNewNode() { return cnt++; }

void UP(int ind) {
    sum(ind) = sum(lc(ind)) + sum(rc(ind));
}

void build(int ind, int l, int r) {
    tree[ind].cnt = (r - l + 1);
    if (l == r) {
        tree[ind].sum = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    tree[ind].lind = getNewNode();
    tree[ind].rind = getNewNode();
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    UP(ind);
    return ;
}

void DOWN(int ind) {
    if (tag(ind) != 0) {
        tag(lc(ind)) += tag(ind);
        tag(rc(ind)) += tag(ind);
        sum(lc(ind)) += tag(ind) * cnt(lc(ind));
        sum(rc(ind)) += tag(ind) * cnt(rc(ind));
        tag(ind) = 0;
    }
    return ;
}
//区间修改
void modify_range(int ind, int x, int y, long long d, int l, int r) {
    if (l >= x && r <= y) {
        tag(ind) += d;
        sum(ind) += cnt(ind) * d;
        return ;
    }
    DOWN(ind);
    int mid = (l + r) >> 1;
    if (x <= mid) modify_range(lc(ind), x, y, d, l, mid);
    if (y > mid) modify_range(rc(ind), x, y, d, mid + 1, r);
    UP(ind);
    return ;
}

long long query(int ind, int x, int y, int l, int r) {
    if (l >= x && r <= y) {
        return sum(ind);
    }
    long long ans = 0, mid = (l + r) >> 1;
    DOWN(ind);
    if (x <= mid) ans += query(lc(ind), x, y, l, mid);
    if (y > mid) ans += query(rc(ind), x, y, mid + 1, r);
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    build(root, 1, n);

    for (int i = 0; i < m; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c;
        if (a == 1) {
            cin >> d;
            modify_range(root, b, c, d, 1, n);
        } else {
            cout << query(root, b, c, 1, n) << endl;
        }
    }
    
    return 0;
}
