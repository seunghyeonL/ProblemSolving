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
        bfs로 최소횟수 찾기
    */

    int N, K; // 수빈, 동생
    cin >> N >> K;
    const int INF = 1e9;

    vector<int> dist(100001, INF);

    queue<int> q;
    q.push(N);
    dist[N] = 0;

    while (!q.empty())
    {
        int cx = q.front();
        q.pop();

        if (cx == K)
            break;

        for (int nx : {cx - 1, cx + 1, 2 * cx})
        {
            if (nx >= 0 && nx <= 100000 && dist[nx] > dist[cx] + 1)
            {
                q.push(nx);
                dist[nx] = dist[cx] + 1;
            }
        }
    }

    cout << dist[K] << '\n';
    // inputFileStream.close();
    return 0;
}
