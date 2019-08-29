/*************************************************************************
	> File Name: 222.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月28日 星期三 11时36分30秒
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
#define lc(ind) (ind << 1)
#define rc(ind) ((ind << 1) + 1)
struct node {
    int sum;
} tree[(MAX_N << 2) + 5];
int root = 1;
int arr[MAX_N + 5]; //原数组
//三种操作：建立   单点修改  区间查询
void UP(int ind) {
    tree[ind].sum = max(tree[lc(ind)].sum, tree[rc(ind)].sum);
}
void build(int ind, int l, int r) {
    if (l == r) {
        tree[ind].sum = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    UP(ind);
    return ;
}

//将 x 位置的数 改成y
void modify(int ind, int x, int y, int l, int r) {
    if (l == r) {
        //if (l == x) {
            tree[ind].sum = y;
            return;
        //}
    }
    int mid = (l + r) >> 1;
    if (x <= mid) modify(lc(ind), x, y, l, mid);
    else modify(rc(ind), x, y, mid + 1, r);
    UP(ind);
    return ;
}

//区间查询 查询 x 到 y 之间的和值
int query(int ind, int x, int y, int l, int r) {
    //当 l～r 完全包含在  x～y 时，他是我们需要的一部分，那么就返回。
    if (x <= l && y >= r) {
        return tree[ind].sum;
    }
    int ans = 0x80000000, mid = (l + r) >> 1;
    if (x <= mid) ans = max(ans, query(lc(ind), x, y, l, mid));
    if (y > mid) ans = max(ans, query(rc(ind), x, y, mid + 1, r));
    return ans;
}

int main() {
   int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(root, 1, n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) modify(root, b, c, 1, n);
        else cout << query(root, b, c, 1, n) << endl;
    }
    
    return 0;
}
