#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int NMX = 200;
int N, M, K;
int dist[NMX + 1][NMX + 1];
vector<int> house;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
     */

    cin >> N >> M;
    for (int u = 1; u <= N; u++)
        for (int v = 1; v <= N; v++)
            dist[u][v] = INF;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for (int u = 1; u <= N; u++)
        dist[u][u] = 0;

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    cin >> K;

    for (int i = 1; i <= K; i++)
    {
        int h;
        cin >> h;
        house.push_back(h);
    }

    int mn = INF;
    vector<int> cdd;
    for (int tv = 1; tv <= N; tv++)
    {
        int mx = 0;
        for (int h : house)
        {
            mx = max(mx, dist[tv][h] + dist[h][tv]);
        }

        if (mn == mx)
        {
            cdd.push_back(tv);
        }
        else if (mn > mx)
        {
            mn = mx;
            cdd.clear();
            cdd.push_back(tv);
        }
    }

    for (int tv : cdd)
        cout << tv << ' ';

    // inputFileStream.close();
    return 0;
}