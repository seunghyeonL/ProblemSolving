#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int NMX = 20;
int N;

int dist[NMX + 1][NMX + 1];
bool rmv[NMX + 1][NMX + 1];

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

    cin >> N;
    for (int u = 1; u <= N; u++)
        for (int v = 1; v <= N; v++)
            cin >> dist[u][v];

    bool impossible = false;
    for (int k = 1; k <= N && !impossible; k++)
        for (int i = 1; i <= N && !impossible; i++)
            for (int j = 1; j <= N && !impossible; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    impossible = true;
                }
                else if (dist[i][j] == dist[i][k] + dist[k][j] && k != i && k != j)
                {
                    rmv[i][j] = true;
                }
            }

    if (impossible)
    {
        cout << -1;
        return 0;
    }

    int ans = 0;
    for (int u = 1; u <= N - 1; u++)
        for (int v = u + 1; v <= N; v++)
        {
            if (!rmv[u][v])
                ans += dist[u][v];
        }

    cout << ans;

    // inputFileStream.close();
    return 0;
}