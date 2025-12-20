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

    int N, S;
    cin >> N >> S;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    int res = 1e9;
    for (int l = 0, r = 0, sum = 0; l < N; l++)
    {
        while (r < N && sum < S)
        {
            sum += v[r++];
        }

        if (sum < S)
            break;

        res = min(res, r - l);
        sum -= v[l];
    }

    cout << (res == 1e9 ? 0 : res) << '\n';

    // inputFileStream.close();
    return 0;
}
