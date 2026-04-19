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
        Homogeneous
    */

    int N, M;
    cin >> N >> M;

    vector<vector<int>> results;
    vector<int> cur;
    function<void()> homo = [&]()
    {
        if (cur.size() == M)
        {
            results.push_back(cur);
            return;
        }

        for (int i = 1; i <= N; i++)
        {
            cur.push_back(i);
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
