#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges)
{
    int vsize = info.size();

    vector<vector<int>> adj(vsize);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 양까지의 최소거리
    vector<int> priority(vsize, -1);

    // priority 설정 dfs
    // 노드 -> priority
    vector<int> visited(vsize);
    int INF = 20;

    function<int(int)> setPriority = [&](int cv)
    {
        bool isWolf = info[cv];
        int p = INF;

        for (int nv : adj[cv])
        {
            if (visited[nv])
                continue;
            visited[nv] = 1;

            if (isWolf)
            {
                p = min(p, setPriority(nv) + 1);
            }
            else
            {
                setPriority(nv);
            }
        }

        if (isWolf)
        {
            priority[cv] = p;
        }
        else
        {
            priority[cv] = 0;
        }

        return priority[cv];
    };

    visited[0] = 1;
    setPriority(0);
    fill(visited.begin(), visited.end(), 0);

    // Printc<vector<int>> printc;
    // printc(priority);

    // 프림 느낌으로 탐색
    auto pqComp = [&](int a, int b)
    { return priority[a] > priority[b]; };

    priority_queue<int, vector<int>, decltype(pqComp)> pq(pqComp);
    pq.push(0);
    visited[0] = 1;

    int sheep = 0;
    int wolf = 0;

    auto canChoose = [&](int v)
    { return info[v] == 1 ? sheep - wolf - 1 > 0 : sheep + 1 - wolf > 0; };

    while (!pq.empty())
    {
        vector<int> tmp;
        int cv = pq.top();
        pq.pop();

        bool runFlag = false;
        if (canChoose(cv))
        {
            runFlag = true;
        }
        else
        {
            while (!pq.empty())
            {
                tmp.push_back(cv);
                cv = pq.top();
                pq.pop();

                if (canChoose(cv))
                {
                    runFlag = true;
                    break;
                }
            }
        }

        if (!runFlag)
        {
            break;
        }

        for (int el : tmp)
        {
            pq.push(el);
        }

        if (info[cv])
            wolf++;
        else
            sheep++;

        for (int nv : adj[cv])
        {
            if (visited[nv])
                continue;

            visited[nv] = 1;

            pq.push(nv);
        }
    }

    return sheep;
}