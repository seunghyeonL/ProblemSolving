#include <string>
#include <vector>
#include <unordered_map>
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

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    struct UserData {
        string name;
        int shotNumber;
    };

    unordered_map<string, UserData> usersMap;
    unordered_map<string, vector<UserData *>> rMap;

    for (string name : id_list) {
        usersMap.insert({name, {name, 0}});
        rMap.insert({name, {}});
    }
    
    for (string str : report) {
        vector<string> splitedStr = strSplit(str);
        string shooter{splitedStr[0]};
        string target{splitedStr[1]};

        UserData *targetUser = &usersMap[target];

        auto targetIt =
            find(rMap[shooter].begin(), rMap[shooter].end(), targetUser);

        if (targetIt == rMap[shooter].end()) {
            targetUser->shotNumber++;
            rMap[shooter].push_back(targetUser);
        }
    }

    for (string id : id_list) {
        int mailNum = 0;

        for (UserData *p : rMap[id]) {
            if (p->shotNumber >= k) {
                mailNum++;
            }
        }

        answer.push_back(mailNum);
    }

    return answer;
}