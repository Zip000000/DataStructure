/*************************************************************************
	> File Name: 148.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 14时16分01秒
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

    reverse(str.begin(), str.end());
    
    cout << str << endl;
    return 0;
}
