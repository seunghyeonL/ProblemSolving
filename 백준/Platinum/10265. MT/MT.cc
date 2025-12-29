#include <bits/stdc++.h>
using namespace std;

const int NMX = 1001;
int N, K;
vector<int> biAdj[NMX];
int inDeg[NMX];
bool vis[NMX];
vector<pair<int, int>> clusterInfo; // 연결된 덩어리에서 데려갈 수 있는 사람 {최솟값, 최댓값}

void getClsuterAndCycleSize(int cv, int &clusterSize, int &cycleSize)
{
    vis[cv] = true;

    if (inDeg[cv])
        cycleSize++;

    clusterSize++;

    for (int nv : biAdj[cv])
    {
        if (!vis[nv])
            getClsuterAndCycleSize(nv, clusterSize, cycleSize);
    }
}
int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
       함수 그래프에서 컴포넌트당 사이클은 반드시 하나
       -> leaf pruning으로 시작 사이클 찾기
   */

    cin >> N >> K;

    for (int u = 1; u <= N; u++)
    {
        int v;
        cin >> v;

        biAdj[u].push_back(v);
        biAdj[v].push_back(u);

        inDeg[u]++;
        inDeg[v]++;
    }

    // leaf pruning
    queue<int> q;

    for (int u = 1; u <= N; u++)
    {
        if (inDeg[u] == 1)
        {
            q.push(u);
        }
    }

    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        inDeg[cv] = 0;

        for (int nv : biAdj[cv])
        {
            if (inDeg[nv] > 0 && --inDeg[nv] == 1)
            {
                q.push(nv);
            }
        }
    }

    // cluster마다 [cycle크기, cluster크기] 범위의 모든 값이 가능하고
    // 이 두 값만 알면 됨
    for (int u = 1; u <= N; u++)
    {
        int clusterSize{}, cycleSize{};
        if (!vis[u])
            getClsuterAndCycleSize(u, clusterSize, cycleSize);

        if (clusterSize > 0)
            clusterInfo.emplace_back(cycleSize, clusterSize);
    }

    int csize = clusterInfo.size();

    // dp[i] : i수용 버스로 태울 수 있는 최대 인원
    vector<int> dp(K + 1);

    for (int i = 1; i <= csize; i++)
    {
        for (int j = K; j >= 1; j--)
        {
            auto [l, r] = clusterInfo[i - 1];
            for (int k = l; k <= r; k++)
            {
                if (j - k >= 0)
                    dp[j] = max(dp[j], dp[j - k] + k);
            }
        }
    }

    cout << dp[K] << '\n';

    // inputFileStream.close();
    return 0;
}
