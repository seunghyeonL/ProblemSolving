#include <string>
#include <vector>
#include <algorithm>
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

int solution(vector<vector<string>> book_time)
{
    vector<pair<int, int>> bookMinuteTimes(book_time.size());

    for (auto book : book_time)
    {
        int begin = 60 * stoi(strSplit(book[0], ':')[0]) +
                    stoi(strSplit(book[0], ':')[1]);

        int end = 60 * stoi(strSplit(book[1], ':')[0]) +
                  stoi(strSplit(book[1], ':')[1]) + 10;

        bookMinuteTimes.push_back({begin, end});
    }

    sort(bookMinuteTimes.begin(), bookMinuteTimes.end());

    vector<int> rooms; // rooms[i] : i번째 방이 언제까지 사용중인지 여부.

    for (auto [beginTime, endTime] : bookMinuteTimes)
    {
        bool roomFound = false;
        for (int &roomEndTime : rooms)
        {
            if (roomEndTime <= beginTime)
            {
                roomEndTime = endTime;
                roomFound = true;
                break;
            }
        }

        if (!roomFound)
        {
            rooms.push_back(endTime);
        }
    }

    return rooms.size();
}