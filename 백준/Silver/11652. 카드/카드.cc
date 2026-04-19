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
        정렬하고 연속해서 같은 숫자 카운팅
    */

    int N;
    cin >> N;

    vector<long long> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long res = v[0];
    int maxCnt = 1;
    int cnt = 1;
    long long prevNum = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == prevNum)
        {
            cnt++;
        }
        else
        {
            if (maxCnt < cnt)
            {
                res = prevNum;
                maxCnt = cnt;
            }
            prevNum = v[i];
            cnt = 1;
        }
    }

    if (maxCnt < cnt)
    {
        res = v.back();
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
