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
        거리를 잡고
        가능한지 여부로 이분탐색

        거리를 작게 잡으면 가능하고 거리를 크게 잡으면 불가능
    */

    int N, C;
    cin >> N >> C;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    auto check = [&](int dist)
    {
        // 처음 위치에 공유기 설치
        int cnt = 1;
        int px = v[0];
        for (int i = 1; i < N; i++)
        {
            int cx = v[i];

            if (cx - px < dist)
            {
                continue;
            }
            else
            {
                px = cx;
                cnt++;
            }

            // 현재 거리로 가능
            // 거리 늘리기
            if (cnt >= C)
                return true;
        }

        // 현재 거리로 불가능 ( cnt < C )
        // 거리 줄이기
        return false;
    };

    int l = 1, r = v[N - 1] - v[0];

    while (l <= r)
    {
        int m = (l + r) / 2;

        if (check(m))
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << r << '\n';

    // inputFileStream.close();
    return 0;
}

