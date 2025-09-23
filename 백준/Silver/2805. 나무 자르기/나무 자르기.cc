#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    auto getTreeAmountByLen = [&](int len) -> long long
    {
        long long res = 0;
        for (int el : v)
        {
            res += max(0, el - len);
        }
        return res;
    };

    int l = 0;
    int r = *max_element(v.begin(), v.end());
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (getTreeAmountByLen(mid) >= M)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << r << '\n';

    // inputFileStream.close();
    return 0;
}
