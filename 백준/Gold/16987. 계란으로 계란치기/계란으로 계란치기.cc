#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */
    int N;
    cin >> N;

    vector<int> damage(N);
    vector<int> health(N);

    for (int i = 0; i < N; i++)
    {
        cin >> health[i];
        cin >> damage[i];
    }

    int res = 0;
    int breakCnt = 0;
    function<void(int)> rec = [&](int idx)
    {
        res = max(res, breakCnt);
        if (idx == N)
        {
            return;
        }

        if (health[idx] <= 0)
        {
            rec(idx + 1);
            return;
        }

        for (int i = 0; i < N; i++)
        {
            if (i == idx || health[i] <= 0)
                continue;

            // 부딫히기
            int preBreakCnt = breakCnt;
            health[idx] -= damage[i];
            health[i] -= damage[idx];

            if (health[idx] <= 0)
                breakCnt++;
            if (health[i] <= 0)
                breakCnt++;

            rec(idx + 1);

            health[idx] += damage[i];
            health[i] += damage[idx];
            breakCnt = preBreakCnt;
        }
    };

    rec(0);

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
