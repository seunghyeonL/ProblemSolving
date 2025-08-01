#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

vector<int> solution(vector<long long> numbers)
{
    using ll = long long;
    vector<int> answer;

    int maxBtSize = 0;
    ll N = 1e15;
    while (N > 0)
    {
        maxBtSize++;
        N /= 2;
    }

    auto getReverseBinaryNum = [](ll n)
    {
        vector<int> result;
        while (n > 0)
        {
            result.push_back(n % 2);
            n /= 2;
        }

        return result;
    };

    auto getBtSize = [&](int n)
    {
        int left = 0;
        int right = maxBtSize;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (pow(2, mid + 1) - 1 >= n)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return pow(2, left + 1) - 1;
    };

    function<int(const vector<int> &, int, int, bool)> check = [&](const vector<int> &bn, int left, int right, bool zeroflag)
    {
        if (left > right)
            return 1;

        int mid = (left + right) / 2;

        if (bn[mid] == 0)
        {
            zeroflag = true;
        }
        else if (zeroflag)
        {
            return 0;
        }

        return check(bn, left, mid - 1, zeroflag) && check(bn, mid + 1, right, zeroflag) ? 1 : 0;
    };

    for (ll number : numbers)
    {
        vector<int> bn = getReverseBinaryNum(number);
        int l = bn.size();

        int btSize = getBtSize(l);

        for (int _ = 0; _ < btSize - l; _++)
        {
            bn.push_back(0);
        }

        answer.push_back(check(bn, 0, bn.size() - 1, 0));
    }

    return answer;
}