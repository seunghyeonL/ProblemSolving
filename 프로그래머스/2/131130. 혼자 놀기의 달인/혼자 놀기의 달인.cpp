#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> cards)
{
    // cards 제일 앞에 0추가하기
    // 이 벡터를 단방향 연결리스트로 사용
    // dfs로 사이클 길이들 구해서 priority queue에 넣고 제일 큰거 두개 뽑아서
    // 곱해서 반환

    int size = cards.size();
    vector<int> adjList(size + 1);
    adjList[0] = 0;
    for (int i = 0; i < size; ++i)
    {
        adjList[i + 1] = cards[i];
    }

    vector<bool> visited(size + 1, false);

    function<int(int)> dfs = [&](int node) -> int
    {
        visited[node] = true;
        int result = 1;
        int nextNode = adjList[node];

        if (!visited[nextNode])
        {
            result += dfs(nextNode);
        }

        return result;
    };

    priority_queue<int> pq;

    for (int i = 1; i < size + 1; ++i)
    {
        if (!visited[i])
        {
            pq.push(dfs(i));
        }
    }

    int length1 = pq.top();
    pq.pop();
    if (pq.empty())
    {
        return 0;
    }
    int length2 = pq.top();

    return length1 * length2;
}