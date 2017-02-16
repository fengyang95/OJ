#include <iostream>
#include <cstdio>
using namespace std;
long long int a, b, c, d;

long long int gcd(long long int t1, long long int t2) {
    return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}

void func(long long int m, long long int n) {
    int flag1 = 0;
    int flag2 = 0;
    if (n == 0) {
        cout << "Inf";
        return ;
    }
    if (m == 0) {
        cout << 0;
        return ;
    }
    
    if (m < 0) {
        m = 0 - m;
        flag1 = 1;
    }
    if (n < 0) {
        n = 0 - n;
        flag2 = 1;
    }
    int flag = 0;
    if (flag1 == 1 && flag2 == 1) {
        flag = 0;
    } else if (flag1 == 1 || flag2 == 1) {
        flag = 1;
    }
    if (m == n) {
        if (flag == 1)
            cout << "(-1)";
        else
            cout << "1";
        return;
    }
            
    long long int x = m % n;
    long long int y = m / n;
    if (x == 0) {
        if (flag == 0)
            cout << y;
        else
            cout << "(-" << y << ")";
        return ;
    } else {
        long long int t1 = m - y * n;
        long long int t2 = n;
        long long int t = gcd(t1, t2);
        t1 = t1 / t;
        t2 = t2 / t;
        if (flag == 1) {
            cout << "(-";
        if (y != 0)
            cout << y << " " << t1 << "/" << t2;
            else
                cout << t1 << "/" << t2;
        cout << ")";
        } else {
            if (y != 0)
                cout << y << " " << t1 << "/" << t2;
            else
                cout << t1 << "/" << t2;
        }
    }
}

void add() {
    long long int m, n;
    m = a * d + b * c;
    n = b * d;
    func(a, b);
    cout << " + ";
    func(c, d);
    cout << " = ";
    func(m, n);
    cout << endl;
}

void min() {
    long long int m, n;
    m = a * d - b * c;
    n = b * d;
    func(a, b);
    cout << " - ";
    func(c, d);
    cout << " = ";
    func(m, n);
    cout << endl;
}

void multi() {
    long long int m, n;
    m = a * c;
    n = b * d;
    func(a, b);
    cout << " * ";
    func(c, d);
    cout << " = ";
    func(m, n);
    cout << endl;
}

void div() {
    long long int m, n;
    m = a * d;
    n = b * c;
    func(a, b);
    cout << " / ";
    func(c, d);
    cout << " = ";
    func(m, n);
    cout << endl;
}

int main() {
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    add();
    min();
    multi();
    div();
    return 0;
}