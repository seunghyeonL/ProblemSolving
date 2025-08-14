#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(vector<int> sales, vector<vector<int>> links)
{
    int answer = 0;
    // sales만 0-index인거 유의
    int size = sales.size();

    vector<vector<int>> adj(size + 1);

    for (auto link : links)
    {
        int u = link[0];
        int v = link[1];

        adj[u].push_back(v);
    }

    auto isBoss = [&](int u) { return !adj[u].empty(); };

    // j는 i노드의 참여 여부(0 : 불참, 1 : 참여)
    // dp[i][j]: i노드의 참여 여부에 따른 i의 하위 서브트리의 참여자 매출액 총합
    vector<vector<int>> dp(size + 1, vector<int>(2, -1));

    for (int i = 1; i <= size; i++)
    {
        if (!isBoss(i))
        {
            dp[i][0] = 0;
            dp[i][1] = sales[i - 1];
        }
    }

    // Printc<vector<vector<int>>, Printc<vector<int>>> printc;

    function<int(int, int)> solveRec = [&](int cv, int enter)
    {
        // printc(dp);
        if (dp[cv][enter] >= 0)
            return dp[cv][enter];

        int len = adj[cv].size();

        if (enter) // cv 참여
        {
            int sum = sales[cv - 1];

            for (auto nv : adj[cv])
            {
                sum += min(solveRec(nv, 0), solveRec(nv, 1));
            }

            return dp[cv][enter] = sum;
        }

        // cv 불참
        // 팀원 모두 불참은 x
        int sum = 0;
        int extra = 1e9;
        int extraFlag = true;

        for (auto nv : adj[cv])
        {
            int y = solveRec(nv, 1);
            int n = solveRec(nv, 0);

            if (y > n) // 불참
            {
                extra = min(extra, y - n);
            }
            else // 참여
            {
                extraFlag = false;
            }

            sum += min(y, n);
        }

        if (extraFlag)
        {
            sum += extra;
        }

        return dp[cv][enter] = sum;
    };

    int min1 = solveRec(1, 0);
    int min2 = solveRec(1, 1);
    // printc(dp);

    return min(min1, min2);
}