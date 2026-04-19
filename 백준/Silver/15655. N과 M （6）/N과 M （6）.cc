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
        combination
    */

    int N, M;
    cin >> N >> M;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    vector<vector<int>> results;

    vector<int> cur;
    function<void(int)> comb = [&](int idx)
    {
        if (cur.size() == M)
        {
            results.push_back(cur);
            return;
        }

        if (idx == N)
            return;

        for (int i = idx; i < N; i++)
        {
            cur.push_back(nums[i]);
            comb(i + 1);
            cur.pop_back();
        }
    };

    comb(0);

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
