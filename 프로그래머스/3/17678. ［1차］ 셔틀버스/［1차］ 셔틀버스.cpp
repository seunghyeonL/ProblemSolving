#include <string>
#include <vector>
#include <queue>

using namespace std;

int getMinute(const string &s)
{
    string hs{};
    string ms{};

    int isMinute = false;
    for (char c : s)
    {
        if (c == ':')
        {
            isMinute = true;
            continue;
        }

        if (isMinute)
        {
            ms.push_back(c);
        }
        else
        {
            hs.push_back(c);
        }
    }

    return stoi(ms) + 60 * stoi(hs);
}

string getTimeString(int minute)
{
    int h = minute / 60;
    int m = minute % 60;

    string hs{};
    string ms{};

    hs.push_back('0' + h / 10);
    hs.push_back('0' + h % 10);

    ms.push_back('0' + m / 10);
    ms.push_back('0' + m % 10);

    string result{};
    result += hs;
    result += ':';
    result += ms;
    return result;
}

string solution(int n, int t, int m, vector<string> timetable)
{
    using P = pair<int, bool>; // 정류장 도착시간, 콘인지 여부
    // 탑승 시각(분)으로 이분탐색

    vector<int> bustimes;
    int firstBustime = getMinute("09:00");
    for (int i = 0; i < n; i++)
    {
        bustimes.push_back(firstBustime + i * t);
    }

    // true: 콘, false: 타인
    queue<bool> waiting;

    auto check = [&](int t)
    {
        priority_queue<P, vector<P>, greater<P>> pq;

        for (string tstring : timetable)
        {
            pq.emplace(getMinute(tstring), false);
        }
        pq.emplace(t, true);

        for (auto bustime : bustimes)
        {
            int cnt = 0; // 탑승인원
            while (!pq.empty() && pq.top().first <= bustime && cnt < m)
            {
                if (pq.top().second)
                    return true;

                cnt++;
                pq.pop();
            }
        }

        return false;
    };

    int left = 0;
    int right = getMinute("23:59");

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (check(mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return getTimeString(right);
}