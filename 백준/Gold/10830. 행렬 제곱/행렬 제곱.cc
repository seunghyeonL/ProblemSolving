#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    using ll = long long;
    int N;
    ll M;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> v[i][j];

    auto matrixMul = [&](const vector<vector<int>> &A, const vector<vector<int>> &B) -> vector<vector<int>>
    {
        vector<vector<int>> res(N, vector<int>(N));

        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                {
                    res[i][j] += A[i][k] * B[k][j];
                    res[i][j] %= 1000;
                }

        return res;
    };

    auto matrixFastPower = [&](vector<vector<int>> A, ll p)
    {
        vector<vector<int>> res(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            res[i][i] = 1;

        while (p > 0)
        {
            if (p % 2 == 1)
            {
                res = matrixMul(res, A);
                p--;
            }

            if (p == 0)
                break;

            A = matrixMul(A, A);
            p /= 2;
        }

        return res;
    };

    vector<vector<int>> res = matrixFastPower(v, M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }

    // inputFileStream.close();
    return 0;
}

