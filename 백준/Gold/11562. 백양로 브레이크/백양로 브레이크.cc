#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int NMX = 250;
int N, M, K;

int need[NMX + 1][NMX + 1]; // i -> j로 갈 수 있게 연결해야 하는 최소 길 개수

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
            need[u][v] = INF;

    for (int i = 0; i < M; i++)
    {
        int u, v, b;
        cin >> u >> v >> b;

        need[u][v] = 0;
        need[v][u] = !b;
    }

    for (int u = 1; u <= N; u++)
        need[u][u] = 0;

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                need[i][j] = min(need[i][j], need[i][k] + need[k][j]);

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int u, v;
        cin >> u >> v;

        cout << need[u][v] << '\n';
    }

    // inputFileStream.close();
    return 0;
}