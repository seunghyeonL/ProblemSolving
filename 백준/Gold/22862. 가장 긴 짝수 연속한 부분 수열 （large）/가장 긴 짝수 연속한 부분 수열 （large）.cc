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
        r++ => 길이 증가
        l++ => 길이 감소

        홀수 지울수 있는 횟수 카운팅
    */

    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    int removeCnt = 0;
    int len = 0;
    int mx = 0;

    for (int l = 0, r = 0; l < N; l++)
    {
        while (r < N)
        {
            if (v[r] % 2 == 0)
            {
                len++;
                r++;
            }
            else if (v[r] % 2 == 1 && removeCnt < K)
            {
                removeCnt++;
                r++;
            }
            else
            {
                break;
            }
        }

        mx = max(mx, len);

        // if (r == l)
        //     continue;

        if (v[l] % 2 == 0)
        {
            len--;
        }
        else if (v[l] % 2 == 1)
        {
            removeCnt--;
        }
    }

    cout << mx << '\n';

    // inputFileStream.close();
    return 0;
}
