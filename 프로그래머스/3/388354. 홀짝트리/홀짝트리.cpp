#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <functional>

using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges)
{
    vector<int> answer(2, 0);

    /*
        일단 adj 만들고 클러스터들 뽑기
        각 클러스터마다 루트를 바꿔가며 홀짝트리 or 역홀짝 트리가 되는지 판별 ->
       시간초과

       -> 클러스터의 각 노드의 ( 자신 노드 짝홀 ^ 연결된 노드수 짝홀 )를
       했을때 하나만 다를 경우 홀짝 트리 혹은 역홀짝 트리
    */

    unordered_map<int, vector<int>> adj;
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<unordered_set<int>> clusters;
    unordered_set<int> unused(nodes.begin(), nodes.end());
    function<void(int, unordered_set<int> &)> dfs = [&](int cv, auto &cluster)
    {
        if (!unused.count(cv))
            return;
        unused.erase(cv);

        cluster.insert(cv);

        for (int nv : adj[cv])
        {
            dfs(nv, cluster);
        }
    };

    for (int v : nodes)
    {
        unordered_set<int> cluster;
        dfs(v, cluster);

        if (!cluster.empty())
            clusters.push_back(cluster);
    }

    // 0 : 아무것도 아님, 1 : 홀짝트리, 2 : 역홀짝트리
    auto oddEvenCheck = [&](const unordered_set<int> &cluster)
    {
        int oddEvenNodeNum = 0;
        int reverseOddEvenNodeNum = 0;

        for (int v : cluster)
        {
            // 자식 중 부모는 뺴고 보니까 반대로
            bool isOddEvenNode = !((v % 2) ^ (adj[v].size() % 2));

            if (isOddEvenNode)
                oddEvenNodeNum++;
            else
                reverseOddEvenNodeNum++;
        }

        if (oddEvenNodeNum == 1)
            answer[0]++;

        if (reverseOddEvenNodeNum == 1)
            answer[1]++;
    };

    for (auto cluster : clusters)
    {
        oddEvenCheck(cluster);
    }

    return answer;
}