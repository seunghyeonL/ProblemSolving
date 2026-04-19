#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    double A;
    double B;

    std::cin >> A;
    std::cin >> B;

    std::cout << std::fixed;
    std::cout.precision(10); 
    std::cout << A / B << std::endl;

    return 0;
}
