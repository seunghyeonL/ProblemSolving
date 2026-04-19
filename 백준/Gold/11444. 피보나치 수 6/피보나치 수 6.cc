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
        f1    0 1  f0
        f2    1 1  f1
    */

    using ll = long long;
    ll n;
    cin >> n;

    const int MOD = 1000000007;

    auto matrixMul = [&](const vector<vector<ll>> &A, const vector<vector<ll>> &B) -> vector<vector<ll>>
    {
        int N = A.size();
        int M = A[0].size();
        int K = B[0].size();
        vector<vector<ll>> res(N, vector<ll>(K));

        for (int k = 0; k < M; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < K; j++)
                {
                    res[i][j] += A[i][k] * B[k][j];
                    res[i][j] %= MOD;
                }

        return res;
    };

    auto matrixFastPower = [&](vector<vector<ll>> A, ll p)
    {
        int N = A.size();
        vector<vector<ll>> res(N, vector<ll>(N));
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

    vector<vector<ll>> fibo2{
        {1},
        {1}};

    vector<vector<ll>> fiboMat{
        {0, 1},
        {1, 1}};

    vector<vector<ll>> res = matrixMul(matrixFastPower(fiboMat, n - 1), fibo2);

    cout << res[0][0] << '\n';

    // inputFileStream.close();
    return 0;
}
