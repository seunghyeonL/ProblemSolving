#include <bits/stdc++.h>
using namespace std;

const int NMX = 10000;
const int LMX = 1000000;

int N, L, P;
int pos_oil[LMX + 1];

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
        int a, b;
        cin >> a >> b;

        pos_oil[a] = b;
    }

    cin >> L >> P;

    priority_queue<int> pq;
    int cur_oil = P;
    int cx = 0;

    int ans = 0;

    while (cx < L)
    {
        if (cur_oil == 0)
        {
            if (pq.empty())
            {
                ans = -1;
                break;
            }

            cur_oil += pq.top();
            pq.pop();

            ans++;
        }

        cur_oil--;
        cx++;

        if (pos_oil[cx])
            pq.push(pos_oil[cx]);
    }

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}
