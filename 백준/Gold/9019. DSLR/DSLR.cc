#include <bits/stdc++.h>
using namespace std;

const int MX = 10000;
vector<char> oper_name{'D', 'S', 'L', 'R'};

int dist[MX]; // dp[i] : i -> e 최소 변환 횟수
int pre[MX];
char oper_type[MX]; // nxt[i] : s -> e 최소 변환 경우 i가 어떤 연산으로
                    // 만들어졌는가

void init()
{
    fill(dist, dist + MX, -1);
    fill(pre, pre + MX, -1);
    fill(oper_type, oper_type + MX, 0);
}

int operate_D(int cur)
{
    return (cur * 2) % MX;
}

int operate_S(int cur)
{
    return (cur + MX - 1) % MX;
}

int operate_L(int cur)
{
    cur *= 10;
    int d = cur / MX;

    return (cur % MX) + d;
}

int operate_R(int cur)
{
    int d = cur % 10;
    cur /= 10;

    return cur + d * (MX / 10);
}

void solve()
{
    init();

    int s, e;
    cin >> s >> e;

    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        if (cv == e)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nv;

            if (i == 0)
                nv = operate_D(cv);
            else if (i == 1)
                nv = operate_S(cv);
            else if (i == 2)
                nv = operate_L(cv);
            else if (i == 3)
                nv = operate_R(cv);

            if (dist[nv] >= 0)
                continue;

            q.push(nv);
            dist[nv] = dist[cv] + 1;
            pre[nv] = cv;
            oper_type[nv] = oper_name[i];
        }
    }

    int hv = e;
    stack<char> ans;

    while (hv != s)
    {
        ans.push(oper_type[hv]);
        hv = pre[hv];
    }

    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
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

    int T;
    cin >> T;

    while (--T >= 0)
        solve();

    // inputFileStream.close();
    return 0;
}