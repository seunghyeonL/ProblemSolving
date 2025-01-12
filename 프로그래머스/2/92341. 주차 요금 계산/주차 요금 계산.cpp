#include <string>
#include <vector>
#include <numeric>
#include <map>
#include <utility>

using namespace std;

vector<string> strSplit(string str, char seperator = ' ')
{
    vector<string> result;

    string buffer{};

    for (char chr : str)
    {
        if (chr == seperator)
        {
            result.push_back(buffer);
            buffer.clear();
            continue;
        }

        buffer.push_back(chr);
    }

    if (!buffer.empty())
    {
        result.push_back(buffer);
    }

    return result;
}

int getMinute(string hm) {
    auto splited = strSplit(hm, ':');
    return 60 * stoi(splited[0]) + stoi(splited[1]);
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, pair<int, bool>> m;

    for (string record : records)
    {
        auto splited = strSplit(record);
        string hm = splited[0];
        string cNum = splited[1];
        string inOut = splited[2];

        int minute = getMinute(hm);

        auto it = m.find(cNum);
        if (it == m.end())
        {
            m.insert({cNum, {-1 * minute, false}});
        }
        else
        {
            if (inOut == "IN")
            {
                it->second.first -= minute;
                it->second.second = false;
            }
            else
            {
                it->second.first += minute;
                it->second.second = true;
            }
        }
        // if (cNum == "5961")
        // {
        //     cout << m[cNum].first << " " << m[cNum].second << endl;
        // }
    }

    for (auto [cNum, p] : m)
    {
        auto [minute, outFlag] = p;

        if (!outFlag)
        {
            minute += getMinute("23:59");
            outFlag = true;
        }

        // cout << "cNum: " << cNum << " minute: " << minute
        //      << " outFlag: " << outFlag << '\n';

        minute -= fees[0];
        answer.push_back(fees[1]);
        if (minute > 0)
        {
            answer.back() += minute / fees[2] * fees[3];
            minute %= fees[2];
            if (minute > 0)
            {
                answer.back() += fees[3];
            }
        }
    }

    return answer;
}