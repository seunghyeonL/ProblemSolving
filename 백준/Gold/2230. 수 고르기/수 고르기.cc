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
        투 포인터
    */

    using ll = long long;
    int N, M;
    cin >> N >> M;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int mn = v[N - 1] - v[0];
    for (int l = 0, r = 0; l < N; l++)
    {
        while (r < N && v[r] - v[l] < M)
            r++;

        if (r == N)
            break;

        mn = min(mn, v[r] - v[l]);
    }

    cout << mn << '\n';

    // inputFileStream.close();
    return 0;
}

