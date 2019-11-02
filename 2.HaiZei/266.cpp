/*************************************************************************
	> File Name: 266.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月02日 星期三 13时06分29秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <stack>
using namespace std;
typedef long long ll;
stack<ll> numstk, opstk;
string str;
map<char, int> op;
bool is_num(int i) {
    return (str[i] >= '0' && str[i] <= '9');
}
ll get_num(int &i) {
    int flag = 1;
    ll ret = 0;
    if (str[i] == '-') flag = -1, i += 1;
    while (is_num(i)) {
        ret *= 10, ret += (str[i] - '0');
        i++;
    }
    i -= 1;
    return ret * flag;
}
void count_once() {
    ll num1 = numstk.top();
    numstk.pop();
    ll num2 = numstk.top();
    numstk.pop();
    int nowop = opstk.top();
    opstk.pop();
    ll newnum = 0;
    switch (nowop) {
        case 0: newnum = num1 + num2; break;
        case 1: newnum = num2 - num1; break;
        case 3: newnum = num1 * num2; break;
        case 4: newnum = num2 / num1; break;
        case -2: newnum = pow(num1, num2); break;
    }
    numstk.push(newnum);
}
int main() {
    opstk.push(-100);
    op['('] = op[')'] = -1;
    op['+'] = 0;
    op['-'] = 1;
    op['*'] = 2;
    op['/'] = 3;
    op['^'] = -2;
    getline(cin, str);
    bool optime = false;
    for (int i = 0; i < str.size(); i++) {
        while (str[i] == '(') {
            opstk.push(op[str[i]]), i++;
        }
        if (optime) {
            if (str[i] == '(') {
                while (str[i] == '(') {
                    opstk.push(op[str[i]]), i++;
                }
                    optime = false;
            } else {
                int nowop = op[str[i]];
                while (!op.empty() && opstk.top() != -1 && nowop <= opstk.top()) {
                    count_once();
                }
                if (nowop == -1) {
                    opstk.pop();
                } else {
                    opstk.push(nowop);
                }
                if (nowop != -1) optime = false;
                else optime = true;
            }
        } else {
            ll num = get_num(i);
            numstk.push(num);
            optime = true;
        }
    }
    while (opstk.size() > 1) count_once();
    ll ans = numstk.top();
    cout << ans << endl;

    return 0;
}
