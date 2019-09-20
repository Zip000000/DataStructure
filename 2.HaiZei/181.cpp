/*************************************************************************
	> File Name: 181.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月19日 星期四 18时13分47秒
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
        if (*it >= 'a' && *it <='z') {
            *it += ('A' - 'a');
        } else {
            *it += ('a' - 'A');
        }
    }
    cout << str << endl;
    return 0;
}
