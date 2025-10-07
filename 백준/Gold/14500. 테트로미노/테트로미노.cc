#include <bits/stdc++.h>
using namespace std;

const int NMX = 500;
int board[NMX][NMX];
int N, M;
vector<vector<vector<bool>>> blocks;
vector<vector<bool>> block1{{true, true, true, true}};
vector<vector<bool>> block2{{true, true}, {true, true}};
vector<vector<bool>> block3{{true, false}, {true, false}, {true, true}};
vector<vector<bool>> block4{{true, false}, {true, true}, {false, true}};
vector<vector<bool>> block5{
    {true, true, true},
    {false, true, false},
};
// block3, block4 좌우대칭
vector<vector<bool>> block6{{false, true}, {false, true}, {true, true}};
vector<vector<bool>> block7{{false, true}, {true, true}, {true, false}};

vector<vector<bool>> rotate90(const vector<vector<bool>> &block)
{
    int h = block.size();
    int w = block[0].size();
    vector<vector<bool>> res(w, vector<bool>(h));

    /*
        x' = (c -s)(x)
        y' = (s  c)(y)

        x' = (0 -1)(x)
        y' = (1  0)(y)

        x' = -y
        y' = x

        x' = w - y
        y' = x
    */

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            res[w - 1 - j][i] = block[i][j];

    return res;
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
     */

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    blocks.push_back(block1);
    blocks.push_back(rotate90(blocks.back()));

    blocks.push_back(block2);

    blocks.push_back(block3);
    blocks.push_back(rotate90(blocks.back()));
    blocks.push_back(rotate90(blocks.back()));
    blocks.push_back(rotate90(blocks.back()));

    blocks.push_back(block4);
    blocks.push_back(rotate90(blocks.back()));

    blocks.push_back(block5);
    blocks.push_back(rotate90(blocks.back()));
    blocks.push_back(rotate90(blocks.back()));
    blocks.push_back(rotate90(blocks.back()));

    blocks.push_back(block6);
    blocks.push_back(rotate90(blocks.back()));
    blocks.push_back(rotate90(blocks.back()));
    blocks.push_back(rotate90(blocks.back()));

    blocks.push_back(block7);
    blocks.push_back(rotate90(blocks.back()));

    int answer = 0;
    for (const auto &block : blocks)
    {
        int h = block.size();
        int w = block[0].size();

        for (int i = 0; i <= N - h; i++)
        {
            for (int j = 0; j <= M - w; j++)
            {
                int cur = 0;
                for (int x = 0; x < h; x++)
                {
                    for (int y = 0; y < w; y++)
                    {
                        if (block[x][y])
                        {
                            cur += board[i + x][j + y];
                        }
                    }
                }
                answer = max(answer, cur);
            }
        }
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
