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

        값들을 정렬
        한 값을 고정
        두 값에 대해
        v[l] + v[r]은
        r이 감소하면 감소
        l이 증가하면 증가
        투포인터; 좁히기
    */

    int N;
    cin >> N;

    vector<long long> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long mn = 3 * 1e9 + 1;
    vector<long long> res(3);

    for (int i = 0; i < N - 2; i++)
    {
        int l = i + 1;
        int r = N - 1;

        while (l < r)
        {
            long long sum = v[i] + v[l] + v[r];

            if (mn >= llabs(sum))
            {
                mn = llabs(sum);
                res = {v[i], v[l], v[r]};
            }

            if (sum < 0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }

    for (int el : res)
    {
        cout << el << ' ';
    }
    cout << '\n';

    // inputFileStream.close();
    return 0;
}


