#include <bits/stdc++.h>
using namespace std;
int N, K, M;

// 역과 튜브를 모두 하나의 정점으로 취급
vector<int> adj[101002];
int dist[101002];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    cin >> N >> K >> M;

    for (int t = 100001; t <= 100000 + M; t++)
    {
        for (int j = 0; j < K; j++)
        {
            int s;
            cin >> s;
            adj[t].push_back(s);
            adj[s].push_back(t);
        }
    }

    fill(dist, dist + 100000 + M + 1, -1);

    // 노드번호, 역인지 튜브인지 여부(0 : 튜브, 1 : 역)
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    int answer = -1;
    while (!q.empty())
    {
        auto cv = q.front();
        q.pop();

        if (cv == N)
        {
            answer = dist[N] / 2 + 1;
            break;
        }

        for (int nv : adj[cv])
        {
            if (dist[nv] == -1)
            {
                dist[nv] = dist[cv] + 1;
                q.emplace(nv);
            }
        }
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}