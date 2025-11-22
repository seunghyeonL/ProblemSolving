#include <bits/stdc++.h>
using namespace std;

const int MX = 20000;
int C, N;
int T[MX];
pair<int, int> AB[MX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        닭마다 도울수 있는 소 중 가장 B가 작은 소 돕기
    */

    cin >> C >> N;
    for (int i = 0; i < C; i++)
        cin >> T[i];

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        AB[i] = {a, b};
    }

    sort(T, T + C);
    sort(AB, AB + N);

    priority_queue<int, vector<int>, greater<int>> pq;

    int ans = 0;
    for (int i = 0, j = 0; i < C; i++)
    {
        int t = T[i];

        while (j < N && AB[j].first <= t)
            pq.push(AB[j++].second);

        while (!pq.empty() && pq.top() < t)
            pq.pop();

        if (!pq.empty())
        {
            ans++;
            pq.pop();
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}