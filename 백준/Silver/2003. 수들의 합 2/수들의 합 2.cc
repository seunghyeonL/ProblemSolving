#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    //

    int N, M;
    cin >> N >> M;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    int res = 0;
    for (int l = 0, r = 0, sum = 0; l < N; l++)
    {
        while (r < N && sum + v[r] <= M)
        {
            sum += v[r++];
        }

        if (sum == M)
        {
            res++;
        }

        sum -= v[l];
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}