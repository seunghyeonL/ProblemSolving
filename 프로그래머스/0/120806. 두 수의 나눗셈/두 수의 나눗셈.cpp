#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int num1, int num2) {
    double tmp = (double)num1 / num2 * 1000;
    
    return floor(tmp);
}