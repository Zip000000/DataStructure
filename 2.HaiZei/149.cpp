/*************************************************************************
	> File Name: 149.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 14时17分15秒
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
    getline(cin, str);
    int cnt = 0;
    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] == ' ') break;
        cnt += 1;
    }
    cout << cnt << endl;
    
    return 0;
}
