#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>

using namespace std;

int main () {
    int A, B;
    std::cin >> A >> B;
    if (A>B)
        std::cout << ">" << endl;
    else if (A==B)
        std::cout << "==" << endl;
    else 
        std::cout << "<" << endl;
    return 0;
}