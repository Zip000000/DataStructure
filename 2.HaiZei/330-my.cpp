/*************************************************************************
	> File Name: 330-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月24日 星期六 14时28分23秒
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
#define MAX 100000

struct TreeArr {
    long long c[MAX + 5], n;
    void init(long long n) {
        this->n = n;
        memset(c, 0, sizeof(c));
    }
    long long lowbit(long long x) { return x & (-x); }
    void add(long long i, long long val) {
        while(i <= n) c[i] += val, i += lowbit(i);
    }
    long long query(long long i) {
        long long sum = 0;
        while (i > 0) sum += c[i], i -= lowbit(i);
        return sum;
    }

};

TreeArr c1, c2;
int main() {
    long long n, m, now, pre = 0;;
    cin >> n >> m;
    c1.init(n);
    c2.init(n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &now);
        c1.add(i, now - pre);
        c2.add(i, i * (now - pre));
        pre = now;
    }
    char str[10];
    long long l, r, val;
    long long ind1, ind2;
    for (long long i = 1; i <= m; i++) {
        scanf("%s", str);
        switch (str[0]) {
            case 'C' :{
                scanf("%lld %lld %lld", &l, &r, &val);
                c1.add(l, val);
                c1.add(r + 1, -val);
                c2.add(l, l * val);
                c2.add(r + 1, -((r + 1) * val));
            } break;
            case 'Q' :{
                scanf("%lld %lld", &l, &r);
                ind1 = (r + 1) * c1.query(r) - (c2.query(r));
                ind2 = (l) * c1.query(l - 1) - (c2.query(l - 1));
                printf("%lld\n", ind1 - ind2);
            } break;
        }
    }
    
    
    return 0;
}
