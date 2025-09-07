#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    vector<int> uf(n, -1);

    function<int(int)> findRoot = [&](int u)
    {
        if (uf[u] < 0)
            return u;

        return uf[u] = findRoot(uf[u]);
    };

    auto unionSet = [&](int u, int v) -> bool
    {
        u = findRoot(u);
        v = findRoot(v);

        if (u == v)
            return false;

        // v에 u를 붙일거임
        // union by rank

        if (uf[u] < uf[v])
        {
            swap(u, v);
        }
        else if (uf[u] == uf[v])
        {
            uf[v]--;
        }

        uf[u] = v;

        return true;
    };

    sort(costs.begin(), costs.end(),
         [](const auto &a, const auto &b) { return a[2] < b[2]; });

    // 연결 갯수
    int cnt = 0;
    for (const auto &cost : costs)
    {
        int u = cost[0];
        int v = cost[1];
        int c = cost[2];

        if (unionSet(u, v))
        {
            cnt++;
            answer += c;
        }

        if (cnt == n - 1)
            break;
    }

    return answer;
}