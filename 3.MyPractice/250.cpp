/*************************************************************************
	> File Name: 250.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月02日 星期三 12时10分54秒
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
#define MAX_N 10000000
typedef long long ll;
ll arr[MAX_N + 5];
ll pass[MAX_N + 5];
int main() {
    int n;
    ll sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
    ll ave = sum / n;
    pass[0] = arr[0] + pass[n - 1] - ave;
    for (int i = 1; i < n; i++) {
        pass[i] = arr[i] + pass[i - 1] - ave;
    }

    sort(pass, pass + n);
    ll mid = pass[n / 2];
    
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += abs(pass[i] - mid);
    }
    cout << ans << endl;
    
    return 0;
}
