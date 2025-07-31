#include <string>
#include <vector>
#include <functional>

using namespace std;

vector<string> solution(vector<string> s)
{
    vector<string> answer;
    string s110 = "110";

    auto solve = [&](string str)
    {
        int cnt110 = 0;
        string remain;

        for (char c : str)
        {
            remain.push_back(c);
            int size = remain.size();

            if (size >= 3 && remain[size - 3] == '1' && remain[size - 2] == '1' && remain[size - 1] == '0')
            {
                cnt110++;
                remain.erase(remain.end() - 3, remain.end());
            }
        }

        string result{};
        auto place110 = remain.begin();

        for (auto it = remain.begin(); it != remain.end(); ++it)
        {
            if (*it == '0')
            {
                place110 = it + 1;
            }
        }

        result += string(remain.begin(), place110);
        for (int _ = 0; _ < cnt110; _++)
        {
            result += s110;
        }
        result += string(place110, remain.end());

        answer.push_back(result);
    };

    for (string el : s)
    {
        solve(el);
    }

    return answer;
}