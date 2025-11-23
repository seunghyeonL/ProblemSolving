#include <bits/stdc++.h>
using namespace std;

int N, K;
queue<int> q;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        q.push(i);

    int cnt = 0;
    cout << '<';
    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        if (++cnt < K)
            q.push(n);
        else
        {
            cout << n;

            if (q.size() > 0)
                cout << ", ";

            cnt = 0;
        }
    }
    cout << '>';

    // inputFileStream.close();
    return 0;
}