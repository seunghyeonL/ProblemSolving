#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int M;
    cin >> M;

    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    cout << (M + 1) / 2 << '\n';

    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;

        if (pq1.empty() || pq1.top() >= n)
            pq1.push(n);
        else if (n > pq1.top())
            pq2.push(n);

        while (pq1.size() >= pq2.size() + 2)
        {
            pq2.push(pq1.top());
            pq1.pop();
        }

        while (pq2.size() > pq1.size())
        {
            pq1.push(pq2.top());
            pq2.pop();
        }

        if (i % 2 == 0)
            cout << pq1.top() << ' ';
    }

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

    int T;
    cin >> T;

    while (T-- > 0)
        solve();

    // inputFileStream.close();
    return 0;
}