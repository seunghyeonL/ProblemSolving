#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N;
int dist[101][101];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            dist[i][j] = 1e9;

    while (1)
    {
        int u, v;
        cin >> u >> v;

        if (u == -1)
            break;

        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    
    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int mnDeg = INF;
    vector<int> answer;
    for (int i = 1; i <= N; i++)
    {
        int curMx = *max_element(dist[i] + 1, dist[i] + N + 1);
        if (mnDeg == curMx)
            answer.push_back(i);
        else if (mnDeg > curMx)
        {
            mnDeg = curMx;
            answer.clear();
            answer.push_back(i);
        }
    }

    cout << mnDeg << ' ' << answer.size() << '\n';
    for (int el : answer)
        cout << el << ' ';
    cout << '\n';

    // inputFileStream.close();
    return 0;
}