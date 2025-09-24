#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*

    */

    int N, M;
    cin >> N >> M;

    vector<vector<int>> v1(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> v1[i][j];

    int K;
    cin >> M >> K;

    vector<vector<int>> v2(M, vector<int>(K));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            cin >> v2[i][j];

    vector<vector<int>> res(N, vector<int>(K));

    for (int k = 0; k < M; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < K; j++)
                res[i][j] += v1[i][k] * v2[k][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    // inputFileStream.close();
    return 0;
}