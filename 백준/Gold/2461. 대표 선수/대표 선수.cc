#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> v[i][j];

    // value, class
    vector<pair<int, int>> v1;
    v1.reserve(N * M);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            v1.emplace_back(v[i][j], i);

    sort(v1.begin(), v1.end());

    vector<int> coverArr(N);
    int coverCnt{};

    int mn = 1e9 + 1;
    // 슬라이딩 윈도우로 um.size()가 N이 될때마다 최소 체크해주기
    for (int l = 0, r = 0; l < N * M; l++)
    {
        while (r < N * M && coverCnt < N)
        {
            if (coverArr[v1[r++].second]++ == 0)
            {
                coverCnt++;
            }
        }

        if (coverCnt == N)
        {
            mn = min(mn, v1[r - 1].first - v1[l].first);
        }

        if (r == N * M)
        {
            break;
        }

        if (--coverArr[v1[l].second] == 0)
        {
            coverCnt--;
        }
    }

    cout << mn << '\n';

    // inputFileStream.close();
    return 0;
}