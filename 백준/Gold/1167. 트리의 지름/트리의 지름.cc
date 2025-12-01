#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N;
vector<pair<int, int>> adj[NMX + 1]; // w, v

pair<int, int> get_far_node_and_dist(int sv)
{
    queue<tuple<int, int, int>> q; // sv -> v 거리, cv, pv
    q.emplace(0, sv, 0);

    int far_node = 0;
    int dist = 0;

    while (!q.empty())
    {
        auto [d, cv, pv] = q.front();
        q.pop();

        if (dist < d)
        {
            far_node = cv;
            dist = d;
        }

        for (auto [w, nv] : adj[cv])
        {
            if (nv == pv)
                continue;

            q.emplace(d + w, nv, cv);
        }
    }

    return {far_node, dist};
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int u;
        cin >> u;

        int v, w;
        while (cin >> v)
        {
            if (v == -1)
                break;
            cin >> w;

            adj[u].emplace_back(w, v);
        }
    }

    int tv1 = get_far_node_and_dist(1).first;
    cout << get_far_node_and_dist(tv1).second;

    // inputFileStream.close();
    return 0;
}