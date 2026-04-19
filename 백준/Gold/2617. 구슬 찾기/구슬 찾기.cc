#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> adj1[100]; // 무겁다 연결
vector<int> adj2[100]; // 가볍다 연결
bool visited[100];

void resetVisited()
{
    for (int i = 1; i <= N; i++)
        visited[i] = false;
}

// adj 에 따라 클러스터 사이즈 반환
int dfs(int cv, vector<int> adj[])
{
    visited[cv] = true;
    int res = 1;

    for (int nv : adj[cv])
    {
        if (!visited[nv])
            res += dfs(nv, adj);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        v노드보다 큰 모든 정점의 개수 합이 N / 2 보다 크면 확실히 중간이 아니다
        v노드보다 작은 모든 정점의 개수 합이 N / 2 보다 크면 확실히 중간이 아니다

        무겁다 방향그래프, 가볍다 방향그래프를 만들어서 뻗어나가는 개수 체크하기
    */

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int h, l;
        cin >> h >> l;

        adj1[l].push_back(h);
        adj2[h].push_back(l);
    }

    int res = 0;
    for (int v = 1; v <= N; v++)
    {
        resetVisited();
        int heavyCnt = dfs(v, adj1) - 1;
        resetVisited();
        int lightCnt = dfs(v, adj2) - 1;

        if (heavyCnt > N / 2 || lightCnt > N / 2)
        {
            res++;
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
