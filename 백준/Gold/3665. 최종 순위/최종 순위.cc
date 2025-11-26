#include <bits/stdc++.h>
using namespace std;

const int NMX = 500;
int N, M;
int arr[NMX + 1];           // arr[i] : 작년 i등 팀 번호
bool adj[NMX + 1][NMX + 1]; // arr[i][j] : i보다 j가 등수가 낮은가?
int indeg[NMX + 1];
int ans[NMX + 1];

void reset()
{
    fill(arr + 1, arr + N + 1, 0);
    fill(ans + 1, ans + N + 1, 0);
    fill(indeg + 1, indeg + N + 1, 0);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            adj[i][j] = false;
}

void solve()
{
    cin >> N;
    reset();

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            int higher = arr[i];
            int lower = arr[j];

            adj[higher][lower] = true;
            indeg[lower]++;
        }
    }

    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;

        if (adj[u][v])
        {
            adj[u][v] = false;
            adj[v][u] = true;

            indeg[v]--;
            indeg[u]++;
        }
        else
        {
            adj[v][u] = false;
            adj[u][v] = true;

            indeg[u]--;
            indeg[v]++;
        }
    }

    queue<int> q;

    vector<int> starts;
    for (int i = 1; i <= N; i++)
    {
        if (indeg[i] == 0)
            starts.push_back(i);
    }

    for (int sv : starts)
        q.push(sv);

    bool is_impossible = false;

    for (int rank = 1; rank <= N; rank++)
    {
        if (q.empty() || q.size() > 1)
        {
            is_impossible = true;
            break;
        }

        int cv = q.front();
        q.pop();

        ans[rank] = cv;

        for (int nv = 1; nv <= N; nv++)
        {
            if (!adj[cv][nv])
                continue;

            if (--indeg[nv] == 0)
                q.push(nv);
        }
    }

    if (is_impossible)
        cout << "IMPOSSIBLE" << '\n';
    else
    {
        for (int i = 1; i <= N; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
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
        항상 불가능하거나 가능하다
        ? 는 나오지 않는다.
        왜냐면 애초에 동일한 등수가 없는 입력이 주어지기 때문.
     */

    int T;
    cin >> T;

    while (T-- > 0)
        solve();

    // inputFileStream.close();
    return 0;
}