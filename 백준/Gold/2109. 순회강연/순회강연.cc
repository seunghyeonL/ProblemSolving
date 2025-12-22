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

    vector<pair<int, int>> v(N);

    int d_mx = 0;

    for (int i = 0; i < N; i++)
    {
        int p, d;
        cin >> p >> d;

        d_mx = max(d_mx, d);

        v[i] = {d, p};
    }

    sort(v.begin(), v.end());

    priority_queue<int> pq;

    int ans = 0;
    for (int d = d_mx, i = N - 1; d >= 1; d--)
    {
        while (i >= 0 && v[i].first >= d)
        {
            pq.push(v[i--].second);
        }

        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}