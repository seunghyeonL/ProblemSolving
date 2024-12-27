#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    auto lIt = s.begin();
    auto rIt = s.end();

    while (distance(lIt, rIt) > 2) {
        lIt++;
        rIt--;
    }
    return string(lIt, rIt);
}