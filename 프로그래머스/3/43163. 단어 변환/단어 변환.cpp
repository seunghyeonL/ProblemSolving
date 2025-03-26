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
    vector<int> isVisited(size, false);

    auto canBeConnected = [&](int from, int to) -> bool
    {
        int diffCnt = 0;
        for (int i = 0; i < wordSize; i++)
        {
            if (words[from][i] != words[to][i]) diffCnt++;
        }

        if (diffCnt == 1) return true;
        else return false;
    };

    auto connect = [&](int from, int to) -> void
    {
        adjList[from].push_back(to);
    };

    auto bfs = [&](int start) -> int
    {
        isVisited[start] = true;
        queue<pair<int, int>> q; // {node, distance}

        q.push({start, 0});

        while (!q.empty())
        {
            auto [curNode, dist] = q.front();
            // cout << "q size : " << q.size() << " curNode : " << curNode << " dist : " << dist << '\n';
            q.pop();

            for (int nextNode : adjList[curNode])
            {
                if (!isVisited[nextNode])
                { 
                    if (words[nextNode] == target) return dist + 1;

                    isVisited[nextNode] = true;
                    q.push({nextNode, dist + 1});
                }
            }
        }

        return 0;
    };

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (i == j) continue;

            if (canBeConnected(i, j))
            {
                connect(i, j);
            }
        }
    }

    return bfs(beginIdx);
}