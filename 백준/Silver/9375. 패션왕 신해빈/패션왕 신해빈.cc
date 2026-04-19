#include <bits/stdc++.h>
using namespace std;

int T;
int N;

void solve()
{
    cin >> N;
    unordered_map<string, vector<string>> um;

    for (int i = 0; i < N; i++)
    {
        string cloth, category;
        cin >> cloth >> category;

        um[category].push_back(cloth);
    }

    int answer = 1;
    for (auto [category, clothes] : um)
    {
        answer *= (clothes.size() + 1);
    }

    cout << answer - 1 << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve();
    }

    // inputFileStream.close();
    return 0;
}