#include <bits/stdc++.h>
using namespace std;
const int NMX = 1500;
int N;
int board[NMX][NMX];
int curI[NMX];
priority_queue<pair<int, int>> pq; // 값, 열 idx

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    fill(curI, curI + N, N - 1);

    for (int j = 0; j < N; j++)
        pq.emplace(board[N - 1][j], j);

    int answer{};

    for (int cnt = 0; cnt < N; cnt++)
    {
        auto [v, idx] = pq.top();
        if (cnt == N - 1)
        {
            answer = v;
            break;
        }

        pq.pop();
        pq.emplace(board[--curI[idx]][idx], idx);
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}