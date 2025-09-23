#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    auto getNumberByLen = [&](int len)
    {
        int res = 0;
        for (int el : v)
        {
            res += el / len;
        }
        return res;
    };

    int l = 1;
    int r = *max_element(v.begin(), v.end());

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (getNumberByLen(mid) < M)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << r << '\n';

    // inputFileStream.close();
    return 0;
}
