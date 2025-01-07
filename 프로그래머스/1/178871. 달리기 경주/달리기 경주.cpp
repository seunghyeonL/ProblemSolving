#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, vector<string>::iterator> um;
    for (auto it = players.begin(); it != players.end(); it++) {
        um.insert({*it, it});
    }

    for (string str : callings) {
        auto it = um[str];

        auto frontIt = it - 1;

        um[str] = frontIt;
        um[*frontIt] = it;

        swap(*it, *(it - 1));
    }

    return players;
}