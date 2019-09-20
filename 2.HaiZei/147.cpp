/*************************************************************************
	> File Name: 147.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 14时14分28秒
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
    int a = (str[str.size() - 1] - '0');
    cout << (a & 1 ? "NO" : "YES") << endl;
    
    return 0;
}
