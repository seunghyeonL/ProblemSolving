#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> land, int height)
{
    using T = tuple<int, int, int>; // 비용, 노드, 노드
    int answer = 0;
    int N = land.size();
    // edge를 만들고(오른쪽, 아래쪽으로)
    // cost는 max(abs(h1 - h2) - height, 0)
    // 크루스칼로 mst만들때 비용 찾기

    auto isValid = [N](int x, int y)
    { return x >= 0 && x < N && y >= 0 && y < N; };

    auto getCost = [&](int h1, int h2)
    {
        int diff = abs(h1 - h2);
        return diff <= height ? 0 : diff; 
    };

    vector<T> edges;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int v = j + N * i;
            int h = land[i][j];
            // 아래쪽
            if (isValid(i + 1, j))
            {
                int nv1 = j + N * (i + 1);
                int h1 = land[i + 1][j];
                edges.emplace_back(getCost(h, h1), v, nv1);
            }

            // 오른쪽
            if (isValid(i, j + 1))
            {
                int nv2 = j + 1 + N * i;
                int h2 = land[i][j + 1];
                edges.emplace_back(getCost(h, h2), v, nv2);
            }
        }
    }

    vector<int> uf(N * N, -1);

    function<int(int)> findRoot = [&](int u)
    {
        if (uf[u] < 0)
            return u;

        return uf[u] = findRoot(uf[u]);
    };

    auto unionSet = [&](int u, int v)
    {
        u = findRoot(u);
        v = findRoot(v);

        if (u == v)
            return false;

        if (uf[u] > uf[v])
        {
            uf[u] = v;
        }
        else if (uf[u] == uf[v])
        {
            uf[u] = v;
            uf[v]--;
        }
        else
        {
            uf[v] = u;
        }

        return true;
    };

    sort(edges.begin(), edges.end());

    int cnt = 0;
    for (auto [c, u, v] : edges)
    {
        if (unionSet(u, v))
        {
            answer += c;
            cnt++;
        }

        if (cnt == N * N - 1)
            break;
    }

    return answer;
}