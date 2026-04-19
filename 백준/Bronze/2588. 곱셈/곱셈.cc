#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>

using namespace std;

int main() {
    int A, B;
    int tmp1, tmp2, tmp3;

    std::cin >> A;
    if(A<0 || A>=1000) {
        std::cout << "잘못된 입력";
        return -1;
    }

    std::cin >> B;
    if(B<0 || B>=1000) {
        std::cout << "잘못된 입력";
        return -1;
    }
    
    tmp1 = A*(B%10);
    std::cout << tmp1 << endl;
    tmp2 = A*((B%100)/10);
    std::cout << tmp2 << endl;
    tmp3 = A*(B/100);
    std::cout << tmp3 << endl;
    std::cout << tmp1+tmp2*10+tmp3*100 << endl;
    return 0;
    
    
}