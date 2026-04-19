#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N, Q;

int uf[NMX + 1];

void init()
{
    fill(uf + 1, uf + N + 1, -1);
}

int findRoot(int u)
{
    if (uf[u] < 0)
        return u;
    return uf[u] = findRoot(uf[u]);
}

bool unionSet(int u, int v)
{
    u = findRoot(u);
    v = findRoot(v);

    if (u == v)
        return false;

    // u -> v
    if (uf[u] < uf[v])
        swap(u, v);
    else if (uf[u] == uf[v])
        uf[v]--;

    uf[u] = v;

    return true;
}

struct Event
{
    int t; // 0 : 통나무 시작점, 1 : 통나무 끝점
    int u; // 통나무 번호
    int x; // 이벤트 x좌표
};

auto comp = [](const Event &a, const Event &b)
{
    return a.x == b.x ? a.t < b.t : a.x < b.x;
};

vector<Event> events;

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

    cin >> N >> Q;
    init();

    for (int i = 1; i <= N; i++)
    {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;

        events.push_back({0, i, x1});
        events.push_back({1, i, x2});
    }

    sort(events.begin(), events.end(), comp);

    int active = 0;
    int curRoot = 0;
    for (auto [t, u, x] : events)
    {
        if (t == 0)
        {
            active++;
            if (curRoot)
            {
                unionSet(curRoot, u);
            }

            curRoot = findRoot(u);
        }
        else
        {
            active--;
            if (active == 0)
            {
                curRoot = 0;
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int u, v;
        cin >> u >> v;

        u = findRoot(u);
        v = findRoot(v);

        if (u == v)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    // inputFileStream.close();
    return 0;
}