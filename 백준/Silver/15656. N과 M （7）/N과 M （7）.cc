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
        homogeneous
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
    function<void()> homo = [&]()
    {
        if (cur.size() == M)
        {
            results.push_back(cur);
            return;
        }

        for (int i = 0; i < N; i++)
        {
            cur.push_back(nums[i]);
            homo();
            cur.pop_back();
        }
    };

    homo();

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
