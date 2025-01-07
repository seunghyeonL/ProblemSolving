#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    bool isFirstChar = true;
    for (char &chr : s) {
        if (chr == ' ') {
            answer += chr;
            isFirstChar = true;
            continue;
        }

        if (isFirstChar) {
            chr = toupper(chr);
            answer += chr;
            isFirstChar = false;
        } else {
            chr = tolower(chr);
            answer += chr;
        }
    }

    return answer;
}