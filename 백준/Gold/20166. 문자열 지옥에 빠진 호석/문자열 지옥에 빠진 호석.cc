#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using T = tuple<int, int, string>;
const int NMMX = 10;
const int KMX = 1000;
int N, M;
int K;
char board[NMMX][NMMX];

vector<string> strs;
unordered_map<string, int> um; // 문자열 : 문자열을 만들 수 있는 경우의 수

vector<P> moves{
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
    {1, 1},
    {-1, 1},
    {1, -1},
    {-1, -1},
};

queue<T> q; // x, y, cnt

void bfs(int sx, int sy)
{
    q.emplace(sx, sy, string{board[sx][sy]});

    int cnt = 0;
    while (!q.empty() && cnt < 100000)
    {
        cnt++;
        auto [cx, cy, str] = q.front();
        q.pop();

        if (um.count(str))
        {
            um[str]++;
        }

        if (str.size() == 5)
            continue;

        for (auto [dx, dy] : moves)
        {
            int nx = (cx + dx + N) % N;
            int ny = (cy + dy + M) % M;

            str.push_back(board[nx][ny]);
            q.emplace(nx, ny, str);
            str.pop_back();
        }
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
        8^5 = 2^15 ~= 1000 * 32 = 32000
        board 타일 개수 <= 100

        완전탐색 : 3200000 -> 가능
    */

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = line[j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        string str;
        cin >> str;
        strs.push_back(str);
        um[str] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            bfs(i, j);
        }
    }

    for (auto str : strs)
    {
        cout << um[str] << '\n';
    }

    // inputFileStream.close();
    return 0;
}