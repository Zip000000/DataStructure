/*************************************************************************
	> File Name: 177.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月21日 星期六 00时12分57秒
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

int main() {
    string str;
    cin >> str;
    int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < str.size(); j++) {
            int ind = (cnt + j) % str.size();
            cout << str[ind];
        }
        cout << endl;
        cnt += str.size();
        cnt -= 2;
        cnt %= str.size();
    }

    return 0;
}
