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
        그리디
        제일 가치가 높은거 부터 넣을수 있는 제일 작은 가방에 채우기
    */

    using ll = long long;
    using P = pair<ll, ll>;

    int N, K;
    cin >> N >> K;

    priority_queue<P> pq;
    for (int i = 0; i < N; i++)
    {
        int w, v;
        cin >> w >> v;
        pq.emplace(v, w);
    }

    multiset<int> s;
    for (int i = 0; i < K; i++)
    {
        int w;
        cin >> w;
        s.insert(w);
    }

    ll res = 0;
    while (!pq.empty() && !s.empty())
    {
        auto [v, w] = pq.top();
        pq.pop();

        if (auto it = s.lower_bound(w); it != s.end())
        {
            res += v;
            s.erase(it);
        }
    }

    cout << res << '\n';
    // inputFileStream.close();
    return 0;
}
