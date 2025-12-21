#include <bits/stdc++.h>
using namespace std;

int N;
multiset<int, greater<int>> s;

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
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    int ans = 0;
    while (!s.empty())
    {
        int n = *s.begin();
        s.erase(s.begin());

        while (true)
        {
            auto it = s.upper_bound(n);
            if (it == s.end())
                break;

            n = *it;
            s.erase(it);
        }

        // 탑 하나 만듬

        ans++;
    }

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}
