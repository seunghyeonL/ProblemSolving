#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> strSplit(string str, char seperator = ' ') {
    vector<string> result;

    string buffer{};

    for (char chr : str) {
        if (chr == seperator) {
            result.push_back(buffer);
            buffer.clear();
            continue;
        }

        buffer.push_back(chr);
    }

    if (!buffer.empty()) {
        result.push_back(buffer);
    }

    return result;
}

bool comp(string a, string b) {
    return stoi(a) < stoi(b);
}

string solution(string s) {
    string answer = "";

    auto v = strSplit(s);

    sort(v.begin(), v.end(), comp);

    answer += v[0];
    answer += " ";
    answer += v[v.size() - 1];

    return answer;
}
