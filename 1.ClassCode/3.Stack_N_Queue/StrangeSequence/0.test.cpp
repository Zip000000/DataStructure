/*************************************************************************
	> File Name: 0.test.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月19日 星期五 14时56分08秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <time.h>
#define MAX 100000
int s[MAX];
int  top = 0;
int arr1[MAX];
int arr2[MAX];

void add(int *arr, int n, int ind, int val) {
    for(int i = ind; i < n; i++) arr[i] += val;
    return;
}
int main() {
    srand(time(0));
    int n;
    cin >> n;
    s[++top] = 0;
    int p = rand() % n + 1;
    for (int i = 1; i <= p; i++) {
        int pos = rand() % (top + 1);
        if (pos < top) {
            if (arr1[s[pos + 1]] - arr1[s[pos]] == 1) add(arr1, s[pos] + 1, i, rand() % 10 + 5);
            if (arr2[s[pos + 1]] - arr2[s[pos]] == 1) add(arr2, s[pos] + 1, i, rand() % 10 + 5);
        }
        int val1 = rand() % (pos == top ? 20 : arr1[s[pos + 1]] - arr1[s[pos]] - 1) + 1;
        int val2 = rand() % (pos == top ? 20 : arr2[s[pos + 1]] - arr1[s[pos]] - 1) + 1;
        arr1[i] = arr1[s[pos]] + val1;
        arr2[i] = arr2[s[pos]] + val2;
        while (arr1[s[top]] > arr1[i]) --top;
        s[++top] = i;
    }
    for (int i = p + 1; i <= n; i++) {
        arr1[i] = rand() % 10000;
        arr2[i] = rand() % 10000;
    }
    for (int i = 1; i <= n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        cout << arr2[i] << " " ;
    }
    cout << endl;
    return 0;

}
