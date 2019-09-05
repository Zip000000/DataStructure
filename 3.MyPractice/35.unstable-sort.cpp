/*************************************************************************
	> File Name: 35.unstable-sort.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月03日 星期二 18时16分34秒
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

#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}

void select_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (num[ind] > num[j]) ind = j;
        }
        swap(num[i], num[ind]);
    }
}

void quick_sort(int *num, int l, int r) {
    if (l >= r) return;
    int x = l, y = r, z = num[l];

    while (x < y) {
        while (x < y && num[y] > z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] < z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x);
    quick_sort(num, x + 1, r);
    return ;
}


int main() {
    int num[10] = {0,5,6,7,8,3,4,2,9,1};
    int n = 10;
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }

    cout << endl;
    quick_sort(num, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}
