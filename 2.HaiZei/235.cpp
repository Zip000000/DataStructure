/*************************************************************************
	> File Name: 235.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 15时08分41秒
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
        i == 0 || printf(" ");
        cout << vec[i];
    }
    cout << endl;
}
void output(vector<int> vec, int now, int n) {
    vec.push_back(now);
    print(vec);
    if (now < n) {
        output(vec, now + 1, n);
        vec.pop_back();
        output(vec, now + 1, n);
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec;
    output(vec, 1, n);


    return 0;
}
