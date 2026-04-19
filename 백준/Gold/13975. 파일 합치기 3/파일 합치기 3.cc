#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int K;
    cin >> K;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < K; i++)
    {
        int w;
        cin >> w;

        pq.push(w);
    }

    long long ans = 0;
    while (pq.size() > 1)
    {
        long long w1 = pq.top();
        pq.pop();
        long long w2 = pq.top();
        pq.pop();

        ans += w1 + w2;
        pq.push(w1 + w2);
    }

    cout << ans << '\n';
}


int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int T;
    cin >> T;
    while (--T >= 0)
        solve();

    // inputFileStream.close();
    return 0;
}