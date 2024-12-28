#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    string result = "";
    string buffer = "";
    map<string, int> m;
    m.insert({"zero", 0});
    m.insert({"one", 1});
    m.insert({"two", 2});
    m.insert({"three", 3});
    m.insert({"four", 4});
    m.insert({"five", 5});
    m.insert({"six", 6});
    m.insert({"seven", 7});
    m.insert({"eight", 8});
    m.insert({"nine", 9});
    
    for (int i = 0 ; i < s.size() ; i++) {
        char el = s.at(i);
        if (isdigit(el)) {
            result += el;
        } else {
            buffer += el;
            auto bufIt = m.find(buffer);
            if (bufIt != m.end()) {
                result += to_string(bufIt->second);
                buffer = "";
            }
        }
    }
    return stoi(result);
}
