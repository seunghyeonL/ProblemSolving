#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N, M;
    cin >> N >> M;

    vector<string> v1(N);
    vector<string> v2(M);

    for (int i = 0; i < N; i++)
    {
        cin >> v1[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> v2[i];
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<string> res;
    for (int i = 0; i < N; i++)
    {
        if (auto it = lower_bound(v2.begin(), v2.end(), v1[i]); it != v2.end() && *it == v1[i])
        {
            res.push_back(*it);
        }
    }

    cout << res.size() << '\n';
    for (string &dbg : res)
    {
        cout << dbg << '\n';
    }

    // inputFileStream.close();
    return 0;
}