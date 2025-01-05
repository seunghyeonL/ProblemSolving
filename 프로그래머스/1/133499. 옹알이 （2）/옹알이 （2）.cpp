#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    unordered_map<char, string> speaks;

    speaks['a'] = "aya";
    speaks['y'] = "ye";
    speaks['m'] = "ma";
    speaks['w'] = "woo";

    for (string str : babbling) {
        auto it = str.begin();
        string prevStr = "";

        while (true) {
            char chr = *it;

            if (it + 3 == str.end()) {
                string chr3Str = string(it, it + 3);
                if ((chr3Str == speaks['a'] || chr3Str == speaks['w']) &&
                    chr3Str != prevStr) {
                    answer++;
                }
                break;
            } else if (it + 2 == str.end()) {
                string chr2Str = string(it, it + 2);
                if ((chr2Str == speaks['y'] || chr2Str == speaks['m']) &&
                    chr2Str != prevStr) {
                    answer++;
                }
                break;
            } else if (it + 3 < str.end()) {
                string chr3Str = string(it, it + 3);
                string chr2Str = string(it, it + 2);
                if ((chr3Str == speaks['a'] || chr3Str == speaks['w']) &&
                    chr3Str != prevStr) {
                    it = it + 3;
                    prevStr = chr3Str;
                } else if ((chr2Str == speaks['y'] || chr2Str == speaks['m']) &&
                           chr2Str != prevStr) {
                    it = it + 2;
                    prevStr = chr2Str;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    return answer;
}