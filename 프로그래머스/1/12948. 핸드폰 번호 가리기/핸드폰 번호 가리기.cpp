#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string phone_number) {
    fill(phone_number.begin(), phone_number.end() - 4, '*');
    
    return phone_number;
}