/*************************************************************************
	> File Name: 145.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 13时59分34秒
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
    int n;
    cin >> n;
    string ans;
    while (n--) {
        string tmp;
        cin >> tmp;
        if (ans.size() < tmp.size()) ans = tmp;
    }
    
    cout << ans << endl;
    return 0;
}
