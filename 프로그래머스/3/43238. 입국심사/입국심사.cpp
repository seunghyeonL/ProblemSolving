#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times)
{
    using ll = long long;
    ll answer = 0;
    ll maxCheckTime = 1000000000;

    long double TotalCheckSpeed{0};
    for (int time : times)
    {
        TotalCheckSpeed += (long double)(1)/time;
    }

    long double nearTime = n / TotalCheckSpeed;

    ll begin = max<ll>(ll(floor(nearTime)) - maxCheckTime, 0);
    ll end = ll(ceil(nearTime)) + maxCheckTime;

    auto getPeoplePerTime = [&](ll inTime)
    {
        ll result = 0;

        for (int time : times)
        {
            result += inTime/time;
        }

        return result;
    };

    while (begin <= end)
    {
        ll mid = begin + (end - begin) / 2;

        if (getPeoplePerTime(mid) < n)
        {
            begin = mid + 1;
        }
        else
        {
            answer = mid;
            end = mid - 1;
        }
    }
    
    return answer;
}