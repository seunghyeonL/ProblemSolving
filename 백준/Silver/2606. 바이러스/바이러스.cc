#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{

    ios::sync_with_stdio(false); // C++의 std::cin과 std::cout의 동기화 끊기
    cin.tie(nullptr);            // 입출력 독립 실행
    cout.tie(nullptr);

    int N;
    cin >> N;

    int EdgeNumbers;
    cin >> EdgeNumbers;

    vector<vector<int>> adjList(N + 1);
    vector<bool> isVisited(N + 1, false);

    function<int(int)> dfs = [&](int curNode) -> int
    {
        isVisited[curNode] = true;
        int depth = 1;

        for (int nextNode : adjList[curNode])
        {
            if (!isVisited[nextNode])
                depth += dfs(nextNode);
        }

        return depth;
    };

    for (int i = 0; i < EdgeNumbers; i++)
    {
        int from, to;
        cin >> from >> to;

        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    cout << dfs(1) - 1;

    return 0;
}
