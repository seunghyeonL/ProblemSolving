#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), [](auto a, auto b) -> bool {return a>b;});
    return s;
}