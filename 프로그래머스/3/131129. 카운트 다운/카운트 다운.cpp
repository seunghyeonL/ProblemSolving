#include <string>
#include <vector>
#include <functional>

using namespace std;

vector<int> solution(int target)
{
    using P = pair<int, int>;

    auto comp = [](P a, P b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        else
        {
            return a.first < b.first;
        }
    };

    const P init = {1000001, 0};

    vector<P> dp(1000001, init); // dp[i] : 점수 i일때 최소 시행 횟수, 최대 싱글 + 불
    vector<P> moves;             // 한번의 다트 시행에서 {나올수 있는 점수, 싱글 혹은 불인지 여부}

    moves.emplace_back(50, 1); // bool
    for (int i = 1; i <= 20; i++)
    {
        moves.emplace_back(i, 1);     // single
        moves.emplace_back(2 * i, 0); // double
        moves.emplace_back(3 * i, 0); // tripple
    }

    dp[0] = {0, 0};

    function<P(int)> solveRec = [&](int cs)
    {
        if (cs < 0)
            return init;
        if (dp[cs] != init)
            return dp[cs];

        for (auto [ds, dflag] : moves)
        {
            auto [pcnt, pflag] = solveRec(cs - ds);
            P cdp = {pcnt + 1, pflag + dflag};
            dp[cs] = comp(dp[cs], cdp) ? dp[cs] : cdp;
        }

        return dp[cs];
    };

    auto [ans1, ans2] = solveRec(target);

    return vector<int>{ans1, ans2};
}

