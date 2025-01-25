#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> wires)
{
    int answer = n;

    vector<vector<int>> adjList(n + 1, vector<int>{0});

    for (auto wire : wires)
    {
        int node1 = wire[0];
        int node2 = wire[1];
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }

    vector<bool> isVisited(n + 1, false);
    isVisited[0] = true;

    function<int(int)> dfs = [&](int node) -> int
    {
        // prints(isVisited);
        int result = 1;
        isVisited[node] = true;

        for (int nextNode : adjList[node])
        {
            if (!isVisited[nextNode])
            {
                result += dfs(nextNode);
            }
        }

        return result;
    };

    for (auto wire : wires)
    {
        int node1 = wire[0];
        int node2 = wire[1];
        adjList[node1].erase(
            remove(adjList[node1].begin(), adjList[node1].end(), node2),
            adjList[node1].end());
        adjList[node2].erase(
            remove(adjList[node2].begin(), adjList[node2].end(), node1),
            adjList[node2].end());

        vector<int> curLengths;

        for (int i = 1; i <= n; i++)
        {
            if (!isVisited[i])
            {
                curLengths.push_back(dfs(i));
            }
        }

        int curAnswer = curLengths[0] < curLengths[1]
                            ? curLengths[1] - curLengths[0]
                            : curLengths[0] - curLengths[1];

        if (curAnswer < answer)
            answer = curAnswer;

        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
        for (int i = 1; i <= n; i++)
        {
            isVisited[i] = false;
        }
    }

    return answer;
}
