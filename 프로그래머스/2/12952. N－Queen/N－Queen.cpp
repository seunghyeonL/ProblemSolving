#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(int n)
{
    int answer = 0;

    vector<pair<int, int>> queens;

    auto isValid = [&](int x, int y)
    {
        // bool result = x >= 0 && x < n && y >= 0 && y < n;
        bool result = true;
        for (auto queen : queens)
        {
            if (queen.first == x || queen.second == y || abs(x - queen.first) == abs(y - queen.second))
            {
                result = false;
                break;
            }
        }
        return result;
    };

    function<void(int)> setQueen = [&](int i)
    {
        if (i == n)
        {
            answer++;
            return;
        }
        
        for (int j = 0; j < n; j++)
        {
            if (!isValid(i, j))
            {
                continue;
            }

            queens.emplace_back(i, j);
            setQueen(i + 1);
            queens.pop_back();
        }
    };

    setQueen(0);
    
    return answer;
}