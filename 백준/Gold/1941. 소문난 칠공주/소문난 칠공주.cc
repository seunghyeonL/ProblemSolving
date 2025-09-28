#include <bits/stdc++.h>
using namespace std;

char board[25];
bool visited[25];
bool mask[25];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        25C7 = 480700
        그냥 가능한 모든 조합 체크하기
     */

    auto isValid = [](int x, int y)
    { return x >= 0 && x < 5 && y >= 0 && y < 5; };

    vector<pair<int, int>> moves{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < 5; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < 5; j++)
        {
            board[5 * i + j] = line[j];
        }
    }

    fill(mask, mask + 7, true);

    auto isConnected = [&](set<int> &picked) -> bool
    {
        fill(visited, visited + 25, false);

        function<int(int)> dfs = [&](int cv)
        {
            int res = 1;
            visited[cv] = true;

            for (auto [dx, dy] : moves)
            {
                int nx = cv / 5 + dx;
                int ny = cv % 5 + dy;
                if (!isValid(nx, ny))
                    continue;

                int nv = 5 * nx + ny;

                if (!visited[nv] && picked.count(nv))
                {
                    res += dfs(nv);
                }
            }

            return res;
        };

        return dfs(*picked.begin()) == 7;
    };

    int res = 0;

    do
    {
        set<int> picked;
        int scnt = 0;
        for (int i = 0; i < 25; i++)
        {
            if (mask[i])
            {
                if (board[i] == 'S')
                {
                    scnt++;
                }

                picked.insert(i);
            }
        }

        if (scnt < 4)
            continue;

        if (!isConnected(picked))
            continue;

        res++;
    } while (prev_permutation(mask, mask + 25));

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
