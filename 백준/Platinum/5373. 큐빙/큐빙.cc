#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<vector<char>>> cubes;
unordered_map<char, int> dir_idx{{'U', 0}, {'D', 1}, {'F', 2}, {'B', 3}, {'L', 4}, {'R', 5}};

void init_cube()
{
    cubes = {
        {{'w', 'w', 'w'}, {'w', 'w', 'w'}, {'w', 'w', 'w'}},
        {{'y', 'y', 'y'}, {'y', 'y', 'y'}, {'y', 'y', 'y'}},
        {{'r', 'r', 'r'}, {'r', 'r', 'r'}, {'r', 'r', 'r'}},
        {{'o', 'o', 'o'}, {'o', 'o', 'o'}, {'o', 'o', 'o'}},
        {{'g', 'g', 'g'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}},
        {{'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'}},
    };
}

void rotate90_side_0()
{
    char *line[4][3]{
        {&cubes[2][0][0], &cubes[2][0][1], &cubes[2][0][2]},
        {&cubes[4][0][0], &cubes[4][0][1], &cubes[4][0][2]},
        {&cubes[3][0][0], &cubes[3][0][1], &cubes[3][0][2]},
        {&cubes[5][0][0], &cubes[5][0][1], &cubes[5][0][2]},
    };

    for (int i = 0; i < 3; i++)
    {
        char tmp = *line[3][i];
        for (int r = 0; r < 4; r++)
        {
            swap(*line[r][i], tmp);
        }
    }
}

void rotate90_side_1()
{
    char *line[4][3]{
        {&cubes[2][2][0], &cubes[2][2][1], &cubes[2][2][2]},
        {&cubes[5][2][0], &cubes[5][2][1], &cubes[5][2][2]},
        {&cubes[3][2][0], &cubes[3][2][1], &cubes[3][2][2]},
        {&cubes[4][2][0], &cubes[4][2][1], &cubes[4][2][2]},
    };

    for (int i = 0; i < 3; i++)
    {
        char tmp = *line[3][i];
        for (int r = 0; r < 4; r++)
        {
            swap(*line[r][i], tmp);
        }
    }
}

void rotate90_side_2()
{
    char *line[4][3]{
        {&cubes[0][2][0], &cubes[0][2][1], &cubes[0][2][2]},
        {&cubes[5][0][0], &cubes[5][1][0], &cubes[5][2][0]},
        {&cubes[1][2][0], &cubes[1][2][1], &cubes[1][2][2]},
        {&cubes[4][2][2], &cubes[4][1][2], &cubes[4][0][2]},
    };

    for (int i = 0; i < 3; i++)
    {
        char tmp = *line[3][i];
        for (int r = 0; r < 4; r++)
        {
            swap(*line[r][i], tmp);
        }
    }
}

void rotate90_side_3()
{
    char *line[4][3]{
        {&cubes[0][0][2], &cubes[0][0][1], &cubes[0][0][0]},
        {&cubes[4][0][0], &cubes[4][1][0], &cubes[4][2][0]},
        {&cubes[1][0][2], &cubes[1][0][1], &cubes[1][0][0]},
        {&cubes[5][2][2], &cubes[5][1][2], &cubes[5][0][2]},
    };

    for (int i = 0; i < 3; i++)
    {
        char tmp = *line[3][i];
        for (int r = 0; r < 4; r++)
        {
            swap(*line[r][i], tmp);
        }
    }
}

void rotate90_side_4()
{
    char *line[4][3]{
        {&cubes[0][0][0], &cubes[0][1][0], &cubes[0][2][0]},
        {&cubes[2][0][0], &cubes[2][1][0], &cubes[2][2][0]},
        {&cubes[1][2][2], &cubes[1][1][2], &cubes[1][0][2]},
        {&cubes[3][2][2], &cubes[3][1][2], &cubes[3][0][2]},
    };

    for (int i = 0; i < 3; i++)
    {
        char tmp = *line[3][i];
        for (int r = 0; r < 4; r++)
        {
            swap(*line[r][i], tmp);
        }
    }
}

void rotate90_side_5()
{
    char *line[4][3]{
        {&cubes[0][2][2], &cubes[0][1][2], &cubes[0][0][2]},
        {&cubes[3][0][0], &cubes[3][1][0], &cubes[3][2][0]},
        {&cubes[1][0][0], &cubes[1][1][0], &cubes[1][2][0]},
        {&cubes[2][2][2], &cubes[2][1][2], &cubes[2][0][2]},
    };

    for (int i = 0; i < 3; i++)
    {
        char tmp = *line[3][i];
        for (int r = 0; r < 4; r++)
        {
            swap(*line[r][i], tmp);
        }
    }
}

void rotate90(int dir)
{
    auto &cube = cubes[dir];

    /*
        c -s
        s  c

        cw 90
        0  1
        -1  0

        x = y
        y = 2 - x
    */

    for (int sx = 0, sy = 0; sy <= 1; sy++)
    {
        int cx = sx, cy = sy;
        char tmp = cube[cx][cy];

        for (int r = 1; r <= 4; r++)
        {
            int nx = cy;
            int ny = 2 - cx;

            swap(tmp, cube[nx][ny]);
            cx = nx;
            cy = ny;
        }
    }

    if (dir == 0)
        rotate90_side_0();
    if (dir == 1)
        rotate90_side_1();
    if (dir == 2)
        rotate90_side_2();
    if (dir == 3)
        rotate90_side_3();
    if (dir == 4)
        rotate90_side_4();
    if (dir == 5)
        rotate90_side_5();
}

void solve()
{
    cin >> N;
    init_cube();

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        int dir = dir_idx[str[0]];

        if (str[1] == '+')
            rotate90(dir);
        else
        {
            rotate90(dir);
            rotate90(dir);
            rotate90(dir);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << cubes[0][i][j];
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

    int T;
    cin >> T;

    while (--T >= 0)
        solve();

    // inputFileStream.close();
    return 0;
}