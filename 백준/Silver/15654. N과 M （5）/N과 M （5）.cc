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
        permutation
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

    vector<int> used(N);
    vector<int> cur;
    function<void()> perm = [&]()
    {
        if (cur.size() == M)
        {
            results.push_back(cur);
            return;
        }

        for (int i = 0; i < N; i++)
        {
            if (used[i])
                continue;

            used[i] = true;
            cur.push_back(nums[i]);
            perm();
            cur.pop_back();
            used[i] = false;
        }
    };

    perm();

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
