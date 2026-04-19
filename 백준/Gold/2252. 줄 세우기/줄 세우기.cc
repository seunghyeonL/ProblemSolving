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
        위상 정렬
    */

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<int> indegrees(N + 1);

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;

        adj[A].push_back(B);
        indegrees[B]++;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (indegrees[i] == 0)
            q.push(i);
    }

    vector<int> res;
    res.reserve(N);

    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        res.push_back(cv);

        for (int nv : adj[cv])
        {
            if (--indegrees[nv] == 0)
            {
                q.push(nv);
            }
        }
    }

    for (int el : res)
    {
        cout << el << ' ';
    }
    cout << '\n';

    // inputFileStream.close();
    return 0;
}
