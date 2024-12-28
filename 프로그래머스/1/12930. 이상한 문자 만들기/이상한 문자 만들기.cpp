#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    int count = 0;
    transform(s.begin(), s.end(), s.begin(), [&count](char c) -> char {
        if (!isalpha(c)) {
            count = 0;
            return c;
        }

        return count++ % 2 == 0 ? toupper(c) : tolower(c);
    });
    return s;
}