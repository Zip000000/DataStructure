/*************************************************************************
	> File Name: 182.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月19日 星期四 18时18分46秒
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
    int ans = 0;
    int tmp;
    int n;
    cin >> n;
    while (n--) {
        cin >> tmp;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
