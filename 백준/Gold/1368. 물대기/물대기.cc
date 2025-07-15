#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    // 우물 팔 지점을 정하고
    // 그 상태에서 최소 비용 연결 구하기?
    //
    using P = pair<int, int>;

    int N;
    cin >> N;

    vector<int> wellCosts(N);
    for (int i = 0; i < N; i++)
    {
        cin >> wellCosts[i];
    }

    vector<vector<int>> roadCosts(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> roadCosts[i][j];
        }
    }

    // 비용, 노드
    vector<vector<P>> minRoadCosts(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            minRoadCosts[i].emplace_back(
                min(wellCosts[j], roadCosts[i][j]),
                j);
        }
    }

    auto getMinCost = [&](int firstWell)
    {
        // 비용, 피연결노드
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> connected(N, false);
        int connectedNum = 0;
        int minCost = 0;

        connected[firstWell] = true;
        connectedNum++;
        minCost += wellCosts[firstWell];

        for (auto [cost, nextNode] : minRoadCosts[firstWell])
        {
            pq.push(
                {cost < wellCosts[nextNode] ? cost : wellCosts[nextNode],
                 nextNode});
        }

        while (connectedNum < N)
        {
            // if (pq.empty()) return -1;
            auto [curCost, curNode] = pq.top();
            pq.pop();

            if (connected[curNode])
                continue;

            connected[curNode] = true;
            connectedNum++;
            minCost += curCost;

            for (auto [nextCost, nextNode] : minRoadCosts[curNode])
            {
                if (connected[nextNode])
                    continue;
                pq.emplace(nextCost, nextNode);
            }
        }

        return minCost;
    };

    int answer = 1e9;
    for (int i = 0; i < N; i++)
    {
        answer = min(answer, getMinCost(i));
    }

    cout << answer;

    // inputFileStream.close();
    return 0;
}
