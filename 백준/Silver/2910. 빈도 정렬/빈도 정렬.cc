#include <bits/stdc++.h>
using namespace std;

int N, C;
int arr[1001];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    cin >> N >> C;

    // 숫자, {빈도, 처음나온 idx}
    unordered_map<int, pair<int, int>> um;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        arr[i] = n;
        if (um.count(n))
        {
            um[n].first++;
        }
        else
        {
            um[n] = {1, i};
        }
    }

    auto comp = [&](int a, int b)
    {
        auto [f1, i1] = um[a];
        auto [f2, i2] = um[b];

        return f1 == f2 ? i1 < i2 : f1 > f2;
    };

    sort(arr, arr + N, comp);

    for (int i = 0; i < N; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    // inputFileStream.close();
    return 0;
}
