#include <bits/stdc++.h>
using namespace std;

const int NMX = 300000;
int N, K;
pair<int, int> J[NMX]; // 무게, 가치
int C[NMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        가장 높은 가치의 보석부터 가능한 가장 작은 가방에 넣기
     */

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int w, v;
        cin >> w >> v;

        J[i] = {w, v};
    }

    sort(J, J + N);

    for (int i = 0; i < K; i++)
    {
        cin >> C[i];
    }

    sort(C, C + K);

    priority_queue<int> pq; // 가격

    long long ans = 0;
    int idx_J = 0;

    for (int i = 0; i < K; i++)
    {
        int c = C[i];

        while (idx_J < N && J[idx_J].first <= c)
            pq.push(J[idx_J++].second);

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