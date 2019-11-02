/*************************************************************************
	> File Name: 324.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月22日 星期四 18时49分47秒
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

#define MAX_N 500000
int cnt = 0;
class Solution {
public:
    int StrToInt(string str) {
        auto iter = str.begin();
        cout << *iter << endl;
        int flag = 1;
        if (*iter == '+') {
            flag = 1, iter += 1;
        } else if (*iter = '-') {
            cout << *iter << endl;
            flag = -1, iter += 1;
        }
        cout << *iter << endl;
        int ans = 0;
        for (; iter < str.end(); iter++) {
            if (*iter < '0' && *iter > '9') return 0;
            ans *= 10;
            ans += (*iter - '0');
        }
        return ans * flag;
    }
};

int main() {
    Solution s;
    string str = "123";
    int ret = s.StrToInt(str);
    cout << ret << endl;
    return 0;

}
