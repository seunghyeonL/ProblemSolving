#include <bits/stdc++.h>
using namespace std;

int N, M;
void solve()
{
    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(M);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < M; i++)
        cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int res = 0;
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        while (j < M && A[i] > B[j])
        {
            j++;
        }

        res += j;
    }

    cout << res << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
    */

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve();
    }
    // inputFileStream.close();
    return 0;
}
