#include <bits/stdc++.h>
using namespace std;

void solve(int N)
{
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    vector<bool> mask(N);
    fill(mask.begin(), mask.begin() + 6, true);

    do
    {
        for (int i = 0; i < N; i++)
        {
            if (mask[i])
                cout << v[i] << ' ';
        }
        cout << '\n';

    } while (prev_permutation(mask.begin(), mask.end()));
    cout << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
     */

    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
            break;
        solve(N);
    }

    // inputFileStream.close();
    return 0;
}
