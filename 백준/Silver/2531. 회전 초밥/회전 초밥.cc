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
        연속해서 k개 먹기
        c는 무상 제공
        가짓수 최대로 만들기
        원형 리스트 -> 2배로
    */

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> v(2 * N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < N; i++)
    {
        v[i + N] = v[i];
    }

    map<int, int> m; // 먹은 종류, 개수
    int mx = 0;      // 가짓수 최댓값

    for (int l = 0, r = 0; l < N; l++)
    {
        while (r < l + k)
        {
            m[v[r++]]++;
        }

        mx = max(mx, int(m.count(c) ? m.size() : m.size() + 1));

        if (m.count(v[l]))
        {
            m[v[l]]--;
            if (m[v[l]] == 0)
            {
                m.erase(v[l]);
            }
        }
    }

    cout << mx << '\n';

    // inputFileStream.close();
    return 0;
}
