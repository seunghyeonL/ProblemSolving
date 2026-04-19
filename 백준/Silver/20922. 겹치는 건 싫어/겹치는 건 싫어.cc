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
        구간 map 사용
        구간내 같은 문자 개수 카운팅
    */

    int N, K;
    cin >> N >> K;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    map<int, int> m;
    int mx = 0;

    for (int l = 0, r = 0; l < N; l++)
    {
        while (r < N)
        {
            if (m.count(v[r]))
            {
                if (m[v[r]] < K)
                {
                    m[v[r]]++;
                    r++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                m[v[r]]++;
                r++;
            }
        }

        mx = max(mx, r - l);

        if (m.count(v[l]))
        {
            m[v[l]]--;
            if (m[v[l]] == 0)
            {
                m.erase(v[l]);
            }
        }
    }

    cout << mx << '\n';

    // inputFileStream.close();
    return 0;
}
