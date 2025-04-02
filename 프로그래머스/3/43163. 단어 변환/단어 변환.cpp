#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;

    words.push_back(begin);
    int size = words.size();
    int beginIdx = size - 1;
    int wordSize = words[0].size();

    vector<vector<int>> adjList(size);
    // vector<int> isVisited(size, 0);
    vector<int> visitedDist(size, -1);

    auto canBeConnected = [&](int from, int to) -> bool
    {
        int diffCnt = 0;
        for (int i = 0; i < wordSize; i++)
        {
            if (words[from][i] != words[to][i])
                diffCnt++;
        }

        return diffCnt == 1;
    };

    auto connect = [&](int from, int to) -> void
    { adjList[from].push_back(to); };

    auto bfs = [&](int start) -> int
    {
        visitedDist[start] = 0;
        // queue<pair<int, int>> q; // {node, distance}
        queue<int> q; // node

        q.push(start);

        while (!q.empty())
        {
            auto curNode = q.front();
            q.pop();

            for (int nextNode : adjList[curNode])
            {
                if (visitedDist[nextNode] == -1)
                {
                    if (words[nextNode] == target)
                        return visitedDist[curNode] + 1;

                    visitedDist[nextNode] = visitedDist[curNode] + 1;
                    q.push(nextNode);
                }
            }
        }

        return 0;
    };

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (i == j)
                continue;

            if (canBeConnected(i, j))
            {
                connect(i, j);
            }
        }
    }

    return bfs(beginIdx);
}
