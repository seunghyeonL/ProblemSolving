#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
int N;
int arr[NMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<string> v;

    for (int i = 0; i < N; i++)
        v.push_back(to_string(arr[i]));

    auto compare = [&](const string &a, const string &b)
    {
        return a + b > b + a;
    };

    sort(v.begin(), v.end(), compare);

    string ans{};

    for (const string &el : v)
        ans += el;

    if (all_of(ans.begin(), ans.end(), [](char c)
               { return c == '0'; }))
        ans = "0";

    cout << ans;

    // inputFileStream.close();
    return 0;
}