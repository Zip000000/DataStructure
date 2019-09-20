/*************************************************************************
	> File Name: 146.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 14时10分20秒
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

    for (string::iterator it = str.begin(); it != str.end(); it++) {
        if (*it == 'Z' || *it == 'z') {
            *it = (*it - ('Z' - 'A'));
        } else if (*it >= 'a' && *it <= 'z' || *it >= 'A' && *it <= 'Z') {
            *it = (*it + 1);
        }
    }
    cout << str << endl;
}
