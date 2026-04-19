#include <bits/stdc++.h>
using namespace std;

const int MX = 2000;
int N, M, K;
char board[MX][MX];
int P_B1[MX + 1][MX + 1]; // x + y % 2 == 0인 경우 B 개수
int P_W1[MX + 1][MX + 1]; // x + y % 2 == 0인 경우 W 개수
int P_B2[MX + 1][MX + 1]; // x + y % 2 == 1인 경우 B 개수
int P_W2[MX + 1][MX + 1]; // x + y % 2 == 1인 경우 W 개수

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

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {

            P_B1[i][j] =
                (board[i - 1][j - 1] == 'B' && (i + j) % 2 == 0 ? 1 : 0) +
                P_B1[i - 1][j] + P_B1[i][j - 1] - P_B1[i - 1][j - 1];

            P_W1[i][j] =
                (board[i - 1][j - 1] == 'W' && (i + j) % 2 == 0 ? 1 : 0) +
                P_W1[i - 1][j] + P_W1[i][j - 1] - P_W1[i - 1][j - 1];

            P_B2[i][j] =
                (board[i - 1][j - 1] == 'B' && (i + j) % 2 == 1 ? 1 : 0) +
                P_B2[i - 1][j] + P_B2[i][j - 1] - P_B2[i - 1][j - 1];

            P_W2[i][j] =
                (board[i - 1][j - 1] == 'W' && (i + j) % 2 == 1 ? 1 : 0) +
                P_W2[i - 1][j] + P_W2[i][j - 1] - P_W2[i - 1][j - 1];
        }
    }

    int ans = N * M;
    for (int i = 0; i <= N - K; i++)
    {
        for (int j = 0; j <= M - K; j++)
        {
            int b1 = P_B1[i + K][j + K] - P_B1[i][j + K] - P_B1[i + K][j] +
                     P_B1[i][j];
            int w1 = P_W1[i + K][j + K] - P_W1[i][j + K] - P_W1[i + K][j] +
                     P_W1[i][j];
            int b2 = P_B2[i + K][j + K] - P_B2[i][j + K] - P_B2[i + K][j] +
                     P_B2[i][j];
            int w2 = P_W2[i + K][j + K] - P_W2[i][j + K] - P_W2[i + K][j] +
                     P_W2[i][j];

            ans = min(ans, min(b1 + w2, b2 + w1));
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}