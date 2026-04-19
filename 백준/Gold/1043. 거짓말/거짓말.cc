#include <bits/stdc++.h>
using namespace std;
int N, M, T;
vector<int> uf(51, -1);

int findRoot(int u)
{
    if (uf[u] < 0)
        return u;
    return uf[u] = findRoot(uf[u]);
}

bool unionSet(int u, int v)
{
    u = findRoot(u);
    v = findRoot(v);

    if (u == v)
        return false;

    // u를 v에 붙이기
    if (uf[u] < uf[v])
        swap(u, v);
    else if (uf[u] == uf[v])
        uf[v]--;

    uf[u] = v;

    return true;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        union find 로 파티별 사람들을 묶고

        파티별로 사람들을 체크하면서 진실을 아는 사람과 엮여있는지 확인하기
    */

    cin >> N >> M >> T;

    // 진실을 아는 사람들
    vector<int> truth;
    for (int i = 0; i < T; i++)
    {
        int h;
        cin >> h;
        truth.push_back(h);
    }

    vector<vector<int>> parties(M + 1);
    for (int p = 1; p <= M; p++)
    {
        int n;
        cin >> n;

        for (int _ = 0; _ < n; _++)
        {
            int h;
            cin >> h;
            parties[p].push_back(h);
        }

        int h0 = parties[p][0];
        for (int h : parties[p])
        {
            unionSet(h0, h);
        }
    }

    vector<bool> needTruth(N + 1, false);
    for (int h : truth)
    {
        needTruth[findRoot(h)] = true;
    }

    int res = 0;
    for (int p = 1; p <= M; p++)
    {
        auto &party = parties[p];
        bool canLie = true;
        for (int h : party)
        {
            if (needTruth[findRoot(h)])
            {
                canLie = false;
                break;
            }
        }

        if (canLie)
            res++;
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

