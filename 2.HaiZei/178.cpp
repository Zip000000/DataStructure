/*************************************************************************
	> File Name: 178.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月21日 星期六 00时07分26秒
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

string get_ans(int n) {
    if (n == 1) return "A";
    string ret;
    string tmp = get_ans(n - 1);
    ret += tmp;
    ret += ('A' - 1 + n);
    ret += tmp;
    return ret;
}

int main() {
    string ans;

    int n;
    cin >> n;

    ans = get_ans(n);
    
    cout << ans << endl;
    return 0;
}
