#include <bits/stdc++.h>
using namespace std;

void turn_on(int idx, vector<int> &v)
{
    if (idx > 0)
        v[idx - 1] ^= 1;

    v[idx] ^= 1;

    if (idx + 1 < v.size())
        v[idx + 1] ^= 1;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    // 처음 스위치를 키고 나머지를 맞추거나 처음 스위치를 끄고 나머지를 맞추기

    const int INF = 1e9;
    int N;
    cin >> N;

    vector<int> S(N);
    vector<int> F(N);
    {
        string s, f;
        cin >> s >> f;

        for (int i = 0; i < N; i++)
            S[i] = s[i];

        for (int i = 0; i < N; i++)
            F[i] = f[i];
    }

    int ans = INF;
    // 첫 스위치를 안누를때
    vector<int> cur = S;
    int cnt = 0;
    for (int i = 1; i < N; i++)
    {
        if (cur[i - 1] != F[i - 1])
        {
            turn_on(i, cur);
            cnt++;
        }
    }

    if (cur.back() == F.back())
    {
        ans = min(ans, cnt);
    }

    // 첫 스위치를 누를때
    cur = S;
    turn_on(0, cur);
    cnt = 1;
    for (int i = 1; i < N; i++)
    {
        if (cur[i - 1] != F[i - 1])
        {
            turn_on(i, cur);
            cnt++;
        }
    }

    if (cur.back() == F.back())
    {
        ans = min(ans, cnt);
    }

    cout << (ans == INF ? -1 : ans);

    // inputFileStream.close();
    return 0;
}
