#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k)
{
    string answer;
    int rmCnt = 0;

    for (char c : number)
    {
        while (!answer.empty() && answer.back() < c && rmCnt < k)
        {
            answer.pop_back();
            ++rmCnt;
        }
        answer.push_back(c);
    }

    return string(answer.begin(), answer.begin() + number.size() - k);;
}