/*************************************************************************
	> File Name: 179.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月20日 星期五 23时49分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#include <cstdio>
#include <cmath>
#define EPSILON 1e-7

double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);
int main() {
    int p;
    int q;
    scanf("%d %d", &p, &q);
    printf("%.4lf\n", bisection(p, q, f));
    return 0;
}

double bisection(int p, int q, double (*func)(int, int, double)) {
	double ans = 0x7fffffff;
    double l = -20, r = 20, mid;
    while (abs(ans) > EPSILON) {
        mid = (l + r) / 2;
        ans = func(p, q, mid);
        if (p > 0) {
            if (ans > 0) r = mid;
            else l = mid;
        } else {
            if (ans > 0) l = mid;
            else r = mid;
        }
        //cout << l << " " << r << " " <<  mid << endl;
    }
    return mid;
}

double f(int p, int q, double x) {
    return p * x + q;
}
