#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int mx = 0;
    unordered_map<int, int> um;
    for (int l = 0, r = 0; l < N; l++)
    {
        while (r < N && um.size() <= 2)
        {
            if (um.size() < 2 || um.count(v[r]))
            {
                um[v[r++]]++;
            }
            else
            {
                break;
            }
        }

        mx = max(mx, r - l);

        if (um.count(v[l]))
        {
            um[v[l]]--;
            if (um[v[l]] == 0)
            {
                um.erase(v[l]);
            }
        }
    }

    cout << mx << '\n';

    // inputFileStream.close();
    return 0;
}
