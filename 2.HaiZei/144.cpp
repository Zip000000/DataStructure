/*************************************************************************
	> File Name: 144.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 13时58分28秒
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
    for (auto it : str) {
        if (it == 'A') cnt += 1;
    }
    cout << cnt << endl;
    
    
    return 0;
}
