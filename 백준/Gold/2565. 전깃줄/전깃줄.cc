#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    using P = pair<int, int>;

    int n;
    cin >> n;

    vector<P> edges(n);
    for (int i = 0; i < n; i++)
    {
        cin >> edges[i].first;
        cin >> edges[i].second;
    }

    sort(edges.begin(), edges.end());

    // idx를 끝으로 하는 최장 부분 수열 길이
    vector<int> lisDP(n, 1);
    int lislen = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (edges[j].second < edges[i].second)
            {
                lisDP[i] = max(lisDP[i], lisDP[j] + 1);
                lislen = max(lislen, lisDP[i]);
            }
        }
    }

    cout << n - lislen;

    // inputFileStream.close();
    return 0;
}