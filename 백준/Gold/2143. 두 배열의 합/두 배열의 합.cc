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
     */

    int T;
    cin >> T;

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int M;
    cin >> M;

    vector<int> B(M);
    for (int i = 0; i < M; i++)
        cin >> B[i];

    vector<int> pA(N + 1);
    pA[0] = 0;
    vector<int> pB(M + 1);
    pB[0] = 0;

    for (int i = 0; i < N; i++)
    {
        pA[i + 1] = pA[i] + A[i];
    }

    for (int i = 0; i < M; i++)
    {
        pB[i + 1] = pB[i] + B[i];
    }

    unordered_map<int, int> mA;
    unordered_map<int, int> mB;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            mA[pA[j] - pA[i]]++;
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = i + 1; j <= M; j++)
        {
            mB[pB[j] - pB[i]]++;
        }
    }

    long long res = 0;
    for (auto [sA, nA] : mA)
    {
        int need = T - sA;

        if (auto it = mB.find(need); it != mB.end())
        {
            res += (long long)it->second * nA;
        }
    }

    cout << res << '\n';
    // inputFileStream.close();
    return 0;
}
