#include <bits/stdc++.h>
using namespace std;
const int NMX = 100000;
int N, M;
vector<int> C[NMX + 1];
int dp[NMX + 1]; // dp[i] : i사원이 받은 칭찬 정도
// root 부터 자기가 받은 칭찬을 children에 더해주기

void propagate(int cv)
{
    for (int nv : C[cv])
    {
        dp[nv] += dp[cv];
        propagate(nv);
    }
}

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

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        int p;
        cin >> p;
        if (p == -1)
            continue;
        C[p].push_back(i);
    }

    for (int i = 0; i < M; i++)
    {
        int u, w;
        cin >> u >> w;

        dp[u] += w;
    }

    propagate(1);

    for (int i = 1; i <= N; i++)
    {
        cout << dp[i] << ' ';
    }

    // inputFileStream.close();
    return 0;
}