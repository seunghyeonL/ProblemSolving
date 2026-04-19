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

    // 위치, 순간이동 횟수
    vector<int> dist(N + 1, -1);

    deque<int> dq;
    dq.push_back(S);
    dist[S] = 0;

    int res = 0;
    while (!dq.empty())
    {
        auto cx = dq.front();
        dq.pop_front();

        if (cx == K)
        {
            break;
        }

        {
            int nx = 2 * cx;
            if (nx >= 0 && nx <= N && dist[nx] == -1)
            {
                dq.push_front(nx);
                dist[nx] = dist[cx];
            }
        }

        for (int nx : {cx - 1, cx + 1})
        {
            if (nx >= 0 && nx <= N && dist[nx] == -1)
            {
                dq.push_back(nx);
                dist[nx] = dist[cx] + 1;
            }
        }
    }

    cout << dist[K] << '\n';

    // inputFileStream.close();
    return 0;
}