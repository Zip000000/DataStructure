/*************************************************************************
	> File Name: 278-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月27日 星期五 17时52分53秒
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
#define MAX_N 1000000

int nxt[MAX_N + 5];
struct Data {
    int nowpos, times;
} ans[MAX_N + 5];
int main() {
    int l;
    cin >> l;
    string str;
    cin >> str;
    int j = -1;
    for (int i = 0; i < str.size(); i++) {
        while (j != -1 && str[i] != str[j]) j = nxt[j];
        nxt[i] = j++;
    }
/*
    for (int i = 0; i < str.size(); i++) {
        cout << "nxt[" << i << "] = " << nxt[i] << endl;
    }
    */
    int n = str.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nxt[i] != 0) continue;
        int len = i;
        for (int j = 1; i - 1 + j * len < n; j++) {
            if (nxt[i - 1 + j * len] == nxt[i - 1] + j * len) {
                ans[cnt].nowpos = i + j * len;
                ans[cnt].times = j + 1;
                cnt += 1;
            }
        }
    }
    sort(ans, ans + cnt, [](const struct Data &a, const struct Data &b) { return a.times < b.times; });
    for (int i = 0; i < cnt; i++) {
        cout << ans[i].nowpos << " " << ans[i].times << endl;
    }
    
    
    
    
    return 0;
}
