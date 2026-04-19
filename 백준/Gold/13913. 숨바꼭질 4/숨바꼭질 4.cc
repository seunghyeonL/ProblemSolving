#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int S, K;
    cin >> S >> K;
    int N = 100000;

    vector<int> dist(N + 1, -1);
    vector<int> pre(N + 1, -1);

    queue<int> q;
    q.push(S);
    dist[S] = 0;

    int res = 0;
    while (!q.empty())
    {
        int cx = q.front();
        q.pop();

        if (cx == K)
        {
            break;
        }

        for (int nx : {cx - 1, cx + 1, 2 * cx})
        {
            if (nx >= 0 && nx <= N && dist[nx] == -1)
            {
                q.push(nx);
                dist[nx] = dist[cx] + 1;
                pre[nx] = cx;
            }
        }
    }

    // Printc<vector<int>>()(vector<int>(dist.begin(), dist.begin() + 20));
    cout << dist[K] << '\n';

    vector<int> history;
    int h = K;
    while (h >= 0)
    {
        history.push_back(h);
        h = pre[h];
    }

    for (int i = history.size() - 1; i >= 0; i--)
    {
        cout << history[i] << ' ';
    }
    cout << '\n';

    // inputFileStream.close();
    return 0;
}