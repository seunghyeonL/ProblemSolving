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
        prefix sum
    */

    int N, M;
    cin >> N >> M;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    // ps[i + 1] : v[0, i] 구간 합
    vector<int> ps(N + 1);
    ps[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        ps[i] = ps[i - 1] + v[i - 1];
    }

    for (int _ = 0; _ < M; _++)
    {
        int i, j;
        cin >> i >> j;

        cout << ps[j] - ps[i - 1] << '\n';
    }

    // inputFileStream.close();
    return 0;
}
