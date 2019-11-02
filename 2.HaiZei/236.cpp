/*************************************************************************
	> File Name: 236.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月02日 星期三 22时27分00秒
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
void print(const vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        i == 0 || cout << " ";
        cout << vec[i];
    }
    cout << endl;
    return ;
}
void output(vector<int> vec, int now, int sum, int n, int m) {
    if (n - now + 1 + sum < m) return ;
    if (sum == m) {
        print(vec);
        return ;
    }
    vec.push_back(now);
    output(vec, now + 1, sum + 1, n, m);
    vec.pop_back();
    output(vec, now + 1, sum, n, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    output(vec, 1, 0, n, m);
    
    return 0;
}
