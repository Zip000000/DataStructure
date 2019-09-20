/*************************************************************************
	> File Name: 235.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 15时08分41秒
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

void output(int now, int n, int l) {
    static string str;
    if (now == n + 1) return ;
    for (int i = now; i <= n; i++) {
        str += to_string(i);
        cout << str << endl;
        output(now + 1, n, l + 1);
        
        str.erase(str.end() - 1);
        output(now + 1, n, l);
    }
}

int main() {

    int n;
    cin >> n;
    output(1, n, 0);
    return 0;
}
