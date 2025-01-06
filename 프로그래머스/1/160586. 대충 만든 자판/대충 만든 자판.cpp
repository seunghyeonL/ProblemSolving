#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> minKeys;
    
    for (string km : keymap) {
        for(int i = 0 ; i < km.size() ; i++) {
            if(minKeys.find(km[i]) == minKeys.end()) {
                minKeys[km[i]] = i + 1;
            } else {
                int prev = minKeys[km[i]];
                minKeys[km[i]] = prev > i + 1 ? i + 1 : prev;
            }
        }
    }
    
    transform(targets.begin(), targets.end(), back_inserter(answer), [&minKeys](auto target)-> auto{
        int result = 0;
        for(char chr : target) {
            if(minKeys.find(chr) == minKeys.end()) {
                return -1;
            }
            result += minKeys[chr];
        }
        return result;
    });
    
    return answer;
}