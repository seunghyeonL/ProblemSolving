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
        1 ~ N 까지 중복없이 오름차순으로 M개를 고른 수열
        combination
    */

    int N, M;
    cin >> N >> M;

    vector<vector<int>> results;
    vector<int> cur;
    function<void(int)> comb = [&](int idx)
    {
        if (cur.size() == M)
        {
            results.push_back(cur);
            return;
        }

        if (idx == N + 1)
            return;

        for (int i = idx; i <= N; i++)
        {
            cur.push_back(i);
            comb(i + 1);
            cur.pop_back();
        }
    };

    comb(1);

    for (const auto &result : results)
    {
        for (int el : result)
        {
            cout << el << ' ';
        }
        cout << '\n';
    }

    // inputFileStream.close();
    return 0;
}