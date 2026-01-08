#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    using P = pair<int, int>;

    int N;
    cin >> N;

    vector<int> W(N + 1);
    vector<vector<int>> job_front(N + 1);

    for (int u = 1; u <= N; u++)
    {
        int w, M;
        cin >> w >> M;

        W[u] = w;

        for (int i = 0; i < M; i++)
        {
            int v;
            cin >> v;

            job_front[u].push_back(v);
        }
    }

    // 1 ~ u - 1 이 모두 계산된 상태면 작업 u 시작시간 확정 가능
    // 작업 u 시작 시간 : max (u보다 우선도 높은 작업이 끝나는 시간 min)
    vector<int> st(N + 1);
    int ans = 0;

    for (int u = 1; u <= N; u++)
    {
        for (int fv : job_front[u])
        {
            st[u] = max(st[u], st[fv] + W[fv]);
        }

        ans = max(ans, st[u] + W[u]);
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
