#include <bits/stdc++.h>
using namespace std;
const int NMX = 2000;
int N, C;
int M;
// adj[i][j] : i마을에서 j마을로 보내는 택배 개수
int adj[NMX + 1][NMX + 1];
// sum[i] : i 앞 마을들에서 i 마을로 보내는 택배 개수 총합
int sum[NMX + 1];

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

    cin >> N >> C;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u][v] = c;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
            sum[i] += adj[j][i];
    }

    // truck[i] : 트럭에 실은 i마을로 보낼 택배 개수
    vector<int> truck(N + 1);
    // 트럭에 남은 자리
    int cap = C;

    /*
            1. 2. 3. 4. 5. 6
        1.     30 0  0  0. 40
        2.        0  0  70 0
        3.           40 0. 0
        4.              0. 0
        5                  60
        6

        1.     30 0  0  0. 0
        2.     0  0  0  20 0
        3.     0  0  40 20 0
        4.     0  0  0  20 0
        5                  60
        6

    */

    int answer = 0;
    for (int town = 1; town <= N; town++)
    {

        cap += truck[town];
        answer += truck[town];
        // cout << truck[town] << ' ';
        truck[town] = 0;

        for (int dest = town + 1; dest <= N; dest++)
        {
            // dest 사이 town에서 적재할때 방해되지 않는 선에서만 적재하기
            // town -> dest로 보내는 적재량
            int mxSum = 0;
            for (int i = town + 1; i < dest; i++)
                mxSum = max(mxSum, sum[i]);

            int num = max(min(adj[town][dest], C - mxSum), 0);
            if (num >= cap)
            {
                truck[dest] += cap;
                cap = 0;
                break;
            }
            else
            {
                truck[dest] += num;
                cap -= num;
            }
        }
    }

    // cout << '\n';
    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
