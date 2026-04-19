#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int M;
    cin >> M;

    auto check = [&](int limit)
    {
        int need = 0;

        for (int el : v)
        {
            need += min(limit, el);
        }

        // need 가 M 이하면 가능 => limit 늘려주기
        // need 가 M 초과면 불가능 => limit 줄여주기
        return need <= M;
    };

    int l = 1;
    int r = *max_element(v.begin(), v.end());

    while (l <= r)
    {
        int m = (l + r) / 2;

        if (check(m))
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << r << '\n';

    // inputFileStream.close();
    return 0;
}