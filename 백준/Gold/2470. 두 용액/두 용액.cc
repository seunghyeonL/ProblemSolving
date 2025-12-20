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
        v[l] + v[r]은
        r이 감소하면 감소
        l이 증가하면 증가
        투포인터; 좁히기
    */

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int l = 0;
    int r = N - 1;
    int mn = 2 * 1e9 + 1;
    int tl{}, tr{};
    while (l < r)
    {
        int sum = v[l] + v[r];
        if (abs(sum) < mn)
        {
            mn = abs(sum);
            tl = v[l];
            tr = v[r];
        }

        if (sum < 0)
        {
            l++;
        }
        else if (sum > 0)
        {
            r--;
        }
        else
            break;
    }

    cout << tl << ' ' << tr << '\n';

    // inputFileStream.close();
    return 0;
}