#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_map<string, int> um;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        if (str.size() < M)
            continue;

        um[str]++;
    }

    vector<pair<string, int>> v(um.begin(), um.end());

    sort(v.begin(), v.end(),
         [](const auto &a, const auto &b)
         {
             const auto &[val_a, freq_a] = a;
             const auto &[val_b, freq_b] = b;

             int sz_a = val_a.size();
             int sz_b = val_b.size();

             if (freq_a == freq_b && sz_a == sz_b)
                 return val_a < val_b;
             else if (freq_a == freq_b)
                 return sz_a > sz_b;
             else
                 return freq_a > freq_b;
         });

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << '\n';
    }

    // inputFileStream.close();
    return 0;
}