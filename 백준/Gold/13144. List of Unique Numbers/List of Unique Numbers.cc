#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 구간 set 슬라이딩 윈도우

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    unordered_set<int> ps;
    long long res = 0;

    for (int l = 0, r = 0; l < N; l++)
    {
        res += r - l;

        while (r < N && !ps.count(v[r]))
        {
            res++;
            ps.insert(v[r++]);
        }

        ps.erase(v[l]);
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}