/*************************************************************************
	> File Name: Z3.买票.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月06日 星期五 23时24分25秒
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
#define MAX_N 80000
struct TreeArr {
    int c[MAX_N + 5], n;
    int lowbit(int x) { return (x & (-x)); }
    void init (int n) {
        this->n = n;
        memset(c, 0, sizeof(c));
    }
    void add(int i, int val) {
        while (i <= this->n) c[i] += val, i += lowbit(i);
    }
    int query(int i) {
        int sum = 0;
        while (i) sum += c[i], i -= lowbit(i);
        return sum;
    }
};
int BinarySearch(TreeArr ta, int key, int n) {
    int l = 1, r = n, mid;
    key += 1;
    while (l <= r) {
        mid = (l + r) / 2;
        int Snow = ta.query(mid);
        if (Snow > key) {
            r = mid - 1;
        } else if(Snow < key) {
            l = mid + 1;
        } else {
            while (ta.query(mid) - ta.query(mid - 1) == 0) mid--;
            //cout << "search " << key << "  return : " << mid << endl;
            return mid;
        }
    }
    //cout << "search " << key << "  return : No " << mid << endl;
    return mid;
}
int main() {
    int n;
    cin >> n;
    TreeArr ta;
    ta.init(n);
    for (int i = 1; i <= n; i++) {
        ta.add(i, 1);
    }
    int *arr = (int *)calloc(sizeof(int), (n + 5));
    int *arr2 = (int *)calloc(sizeof(int), (n + 5));
    int *ans = (int *)calloc(sizeof(int), (n + 5));
    for (int i = 1; i <= n; i++) {
        cin >> arr[i] >> arr2[i];
    }
    //cout << "arr5 = " << arr[5] << endl;
    for (int i = n; i >= 1; --i) {
        //cout <<"第" << i << "次搜索 n - arr[i] = " << n - arr[i] << endl;
        int num = BinarySearch(ta, arr[i], n);
        ans[num] = arr2[i];
        ta.add(num, -1);
        //cout << i <<" : num[" << arr[i] << "] = " << num << endl;
    }
    //cout << "ans :" << endl;
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}

