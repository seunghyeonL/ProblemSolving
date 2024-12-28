#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string result = "";
    int diff = 'z' - 'a' + 1;

    for (int i = 0; i < s.size(); i++) {
        char cur = s.at(i);
        if (cur == ' ') {
            result += cur;
        } else if ('A' <= cur && cur <= 'Z') {
            char after = 'A' + (cur + n - 'A') % diff;
            result += after;
        } else if ('a' <= cur && cur <= 'z') {
            char after = 'a' + (cur + n - 'a') % diff;
            result += after;
        }
    }
    return result;
}