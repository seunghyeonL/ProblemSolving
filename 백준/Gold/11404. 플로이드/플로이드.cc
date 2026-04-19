#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        플로이드
    */

    int INF = 1e9;
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

    for (int i = 0; i < M; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;

        dist[u][v] = min(dist[u][v], c);
    }

    for (int i = 0; i <= N; i++)
    {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
        }
        cout << '\n';
    }
    
    // inputFileStream.close();
    return 0;
}
