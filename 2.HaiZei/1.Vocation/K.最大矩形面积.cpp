/*************************************************************************
	> File Name: K.最大矩形面积.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月06日 星期五 16时58分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <stack>
using namespace std;

#define MAX_N 100000
int arr[MAX_N + 5];
int l[MAX_N + 5];
int r[MAX_N + 5];
int main() {
    stack<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n ; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        if (st.empty()) l[i] = i;
        else l[i] = i - st.top() - 1;
        st.push(i);
    }
    
    for (int i = n - 1; i >= 0 ; i--) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        if (st.empty()) r[i] = (n - 1) - i;
        else r[i] = st.top() - i - 1;
        st.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, arr[i] * (l[i] + r[i] + 1));
    }
    cout << ans << endl;
    
    
    return 0;
}
