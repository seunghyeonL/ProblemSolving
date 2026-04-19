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
        투 포인터
        슬라이드 윈도우
    */

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first;
        cin >> v[i].second;
    }

    int rmx = 1000001;

    for (int l = 0, r = 0, sum = 0; l < rmx; l++)
    {
        while (r < rmx && sum < K)
        {
            for (auto [s, e] : v)
            {
                if (r >= s && r < e)
                {
                    sum++;
                }
            }
            r++;
        }

        if (sum == K)
        {
            cout << l << ' ' << r << '\n';
            return 0;
        }
        else if (sum < K)
        {
            break;
        }

        for (auto [s, e] : v)
        {
            if (l >= s && l < e)
            {
                sum--;
            }
        }
    }

    cout << "0 0" << '\n';

    // inputFileStream.close();
    return 0;
}
