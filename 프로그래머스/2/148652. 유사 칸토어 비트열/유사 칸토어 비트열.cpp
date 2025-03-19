#include <string>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

int solution(int n, long long l, long long r)
{
    using ll = long long;
    
    vector<string> ktMemo0{"0"};
    vector<string> ktMemo1{"1"};

    function<string(int)> generatekt0 = [&](int N) -> string
    {
        if (ktMemo0.size() > N) return ktMemo0[N];

        string prev = generatekt0(N - 1);
        string cur{};
        for (int j = 0; j < 5; j++)
        {
            cur += prev;
        }

        ktMemo0.push_back(cur);
        return cur;
    };

    function<string(int)> generatekt1 = [&](int N)-> string
    {
        if (ktMemo1.size() > N) return ktMemo1[N];

        string prev1 = generatekt1(N - 1);
        string prev0 = generatekt0(N - 1);
        string cur{};
        for (int i = 0; i < 5; i++)
        {
            if (i == 2) cur += prev0;
            else cur += prev1;
        }

        ktMemo1.push_back(cur);
        return cur;
    };

    function<int(ll, ll, int)> count1Num = [&](ll left, ll right, int ktNum) // [left, right]
    {
        int result = 0;
        ll size = 1;
        for (int i = 0 ; i < ktNum ; i++)
        {
            size *= 5;
        }

        if (size == 1) return 1;

        ll nextSize = size / 5;

        ll leftGroup = left / nextSize;
        ll rightGroup = right / nextSize;

        ll leftGroupRemain = left % nextSize;
        ll rightGroupRemain = right % nextSize;
        
        for (ll i = leftGroup ; i <= rightGroup ; i++) // 0, 1, 2, 3, 4
        {
            if (i == 2) continue;
            if (leftGroup == rightGroup)
            {
                result += count1Num(leftGroupRemain, rightGroupRemain, ktNum - 1);
            }
            else if (i == leftGroup)
            {
                result += count1Num(leftGroupRemain, nextSize - 1, ktNum - 1);
            }
            else if (i == rightGroup)
            {
                result += count1Num(0, rightGroupRemain, ktNum - 1);
            }
            else
            {
                result += count1Num(0, nextSize - 1, ktNum - 1);
            }
        }

        return result;
    };
    
    return count1Num(l - 1, r - 1, n);
}