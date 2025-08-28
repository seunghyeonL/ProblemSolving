#include <string>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;

vector<vector<int>> solution(int n, int m, vector<int> a, vector<int> b, int k,
                             int m1, int m2, vector<int> e1, vector<int> e2)
{
    vector<vector<int>> answer;

    /*
        n : 정점 수
        m : 간선 수
        a[i], b[i] : 간선 i로 연결된 정점 쌍
        k : m1 >= k, m2 >= k, m중간 >= k - 2 로 제약하는 값
        m1 : M_0 크기
        m2 : M_t 크기
        e1 : m1 간선정보
        e2 : m2 간선정보
    */

    /*
        e1, e2의 겹치는 간선은 인접한 e1간선도, e2간선도 없다. -> 빼버리기

        e1, e2에 포함된 간선 사이의 adj를 만들고
        간선에 가중치를 두기 -1 -> 제거, 1 -> 생성
        일단 클러스터를 찾고
        가중치 합이 높은 클러스터부터 만들기
        만드는 방법은 생성할곳 양쪽
    */

    vector<vector<pair<int, int>>> adjv(n + 1);
    for (int e = 1; e <= m; e++)
    {
        int u = a[e - 1];
        int v = b[e - 1];

        adjv[u].push_back({v, e});
        adjv[v].push_back({u, e});
    }

    unordered_set<int> e2Set(e2.begin(), e2.end());
    unordered_set<int> edgeToKeep;
    unordered_set<int> edgeToRemove;
    // unordered_set<int> edgeToCreate;
    unordered_set<int> exclusiveEdge;

    for (int e : e1)
    {
        if (e2Set.count(e))
            edgeToKeep.insert(e);
        else
        {
            edgeToRemove.insert(e);
            exclusiveEdge.insert(e);
        }
    }

    for (int e : e2)
    {
        if (!edgeToKeep.count(e))
        {
            // edgeToCreate.insert(e);
            exclusiveEdge.insert(e);
        }
    }

    // 인접간선 adj
    unordered_map<int, vector<int>> adje(m + 1);
    for (int e : exclusiveEdge)
    {
        int u = a[e - 1];
        int v = b[e - 1];

        for (auto [nv, ne] : adjv[u])
        {
            if (e != ne && exclusiveEdge.count(ne))
                adje[e].push_back(ne);
        }

        for (auto [nv, ne] : adjv[v])
        {
            if (e != ne && exclusiveEdge.count(ne))
                adje[e].push_back(ne);
        }
    }

    vector<bool> visited(m + 1);
    for (int e : edgeToKeep)
    {
        visited[e] = true;
    }

    function<void(int, int &, int &)> getClusterInfo =
        [&](int ce, int &clusterWeight, int &endpoint)
    {
        if (visited[ce])
            return;
        visited[ce] = true;

        clusterWeight += edgeToRemove.count(ce) ? -1 : 1;
        endpoint = ce;

        for (int ne : adje[ce])
        {
            getClusterInfo(ne, clusterWeight, endpoint);
        }
    };

    vector<pair<int, int>> clusters;
    for (int e : exclusiveEdge)
    {
        int clusterWeight = 0;
        int endpoint = -1;
        getClusterInfo(e, clusterWeight, endpoint);

        if (endpoint != -1)
        {
            clusters.emplace_back(clusterWeight, endpoint);
        }
    }

    sort(clusters.begin(), clusters.end(),
         [](auto a, auto b) { return a.first > b.first; });

    fill(visited.begin(), visited.end(), false);
    
    function<void(int, int)> toggleNode = [&](int ce, int pe)
    {
        if (edgeToRemove.count(ce))
        {
            answer.push_back({0, ce});

            if (pe)
                answer.push_back({1, pe});
        }
        else if (!pe && adje[ce].size() == 2)
        {
            int ne1 = adje[ce][0];
            visited[ne1] = true;
            answer.push_back({0, ne1});
        }

        bool isEndpoint = true;
        for (int ne : adje[ce])
        {
            if (visited[ne])
                continue;
            visited[ne] = true;

            isEndpoint = false;
            toggleNode(ne, ce);
        }

        if (isEndpoint && !edgeToRemove.count(ce))
            answer.push_back({1, ce});
    };

    for (auto [w, endpoint] : clusters)
    {
        visited[endpoint] = true;
        toggleNode(endpoint, 0);
    }

    return answer;
}
