#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int L, Ml, Mk;
    cin >> L >> Ml >> Mk;
    int C;
    cin >> C;

    vector<int> arr(L + 1);
    for (int i = 1; i <= L; i++)
        cin >> arr[i];

    // 0 1 2
    // 1 1 1

    queue<int> q; // 사거리 안 기관총 발사 기록
    for (int x = 1; x <= L; x++)
    {
        int hp = arr[x];

        // if (!q.empty())
        //     cout << q.front() << ' ' << x << '\n';

        if (!q.empty() && q.front() <= x - Ml)
            q.pop();

        // if (!q.empty())
        //     cout << q.front() << ' ' << x << '\n';

        // cout << '\n';

        // cout << (long long)Mk * (q.size() + 1) << ' ' << hp << '\n';
        // cout << '\n';

        if ((long long)Mk * (q.size() + 1) < hp)
        {
            if (C == 0)
            {
                cout << "NO" << '\n';
                return 0;
            }

            C--;
        }
        else
        {
            q.push(x);
        }
    }

    cout << "YES" << '\n';

    // inputFileStream.close();
    return 0;
}