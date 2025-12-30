#include <bits/stdc++.h>
using namespace std;    

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N;
    cin >> N;
    vector<int> M(N), F(N);

    for (int i = 0; i < N; i++)
        cin >> M[i];

    for (int i = 0; i < N; i++)
        cin >> F[i];

    sort(M.begin(), M.end());
    sort(F.begin(), F.end(), greater<int>());

    int ans = 0;

    int mi = 0, fi = 0;
    while (mi < N && fi < N && M[mi] < 0 && F[fi] > 0)
    {
        if (-M[mi] > F[fi])
        {
            ans++;
            mi++, fi++;
        }
        else
            fi++;
    }

    mi = lower_bound(M.begin(), M.end(), 0) - M.begin();
    fi = lower_bound(F.begin(), F.end(), 0, greater<int>()) - F.begin();

    while (mi < N && fi < N)
    {
        if (M[mi] < -F[fi])
        {
            ans++;
            mi++, fi++;
        }
        else
            fi++;
    }

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}
