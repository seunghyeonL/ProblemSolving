#include <bits/stdc++.h>
using namespace std;
int N, C;
int M;

struct Req
{
    int u, v, w;
};

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        더 빠른 지점에 도달하는 택배부터 우선적으로 싣기
     */

    cin >> N >> C;
    cin >> M;
    vector<Req> reqs;
    // remains[i] : i 마을 -> i + 1 마을 로 갈때 트럭의 빈자리
    vector<int> remains(N + 1, C);

    for (int i = 0; i < M; i++)
    {
        Req req;
        cin >> req.u >> req.v >> req.w;
        reqs.push_back(req);
    }

    sort(reqs.begin(), reqs.end(), [](const Req &a, const Req &b)
         { return a.v == b.v ? a.u < b.u : a.v < b.v; });

    int answer = 0;
    // u -> v로 가는 동안 방해되지 않을 정도만 적재
    for (auto [u, v, w] : reqs)
    {
        int can = w;
        for (int i = u; i < v; i++)
        {
            can = min(can, remains[i]);
        }

        for (int i = u; i < v; i++)
        {
            remains[i] -= can;
        }

        answer += can;
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
