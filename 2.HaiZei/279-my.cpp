/*************************************************************************
	> File Name: 279-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月27日 星期五 18时23分21秒
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
    string stra, strb;
    cin >> stra >> strb;
    stra += stra;
    int len = strb.size();
    int pos = stra.find(strb);
    if (pos == stra.npos) {
        cout << "No" << endl;
        return 0;
    }
    string ans(strb);
    for (int i = 0; i < len; i++) {
        if (stra[i] > ans[0]) continue;
        int com = ans.compare(0, len, stra, i, len);
        //string tmp(stra.begin() + i, stra.begin() + i + len);
        if (com <= 0) continue;
        ans = stra[i, i + len];
        //if (tmp < ans) ans = tmp;
    }
    cout << "Yes" << endl;
    cout << ans << endl;


    return 0;
}

