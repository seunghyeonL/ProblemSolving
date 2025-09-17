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
        greedy
    */

    int N;
    cin >> N;

    vector<pair<int, int>> v(N); // 끝, 시작

    for (int i = 0; i < N; i++)
    {
        cin >> v[i].second;
        cin >> v[i].first;
    }

    sort(v.begin(), v.end());

    int res = 0;
    int ft = 0;

    for (auto [finish, start] : v)
    {
        if (start >= ft)
        {
            res++;
            ft = finish;
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}