#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        한방향으로 합치는 함수, 오른쪽으로 90도 돌리는 함수

        5번 실행했을때 최대인 경우 찾기(4^5 = 2^10 ~= 1000)
    */

    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    // 오른쪽으로 90도 돌리는 함수
    vector<vector<int>> tmp(N, vector<int>(N));
    auto rotate90 = [&]()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                tmp[j][N - 1 - i] = board[i][j];
            }
        }

        board = tmp;
    };

    // 왼쪽으로 합치는 함수
    auto pushLeft = [&]()
    {
        for (int i = 0; i < N; i++)
        {
            bool canMerge = true;
            int mj = 0;
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 0)
                    continue;

                if (mj == 0)
                {
                    board[i][mj] = board[i][j];
                    if (j > mj)
                    {
                        board[i][j] = 0;
                    }

                    mj++;
                    canMerge = true;
                    continue;
                }

                if (board[i][mj - 1] == board[i][j] && canMerge)
                {
                    board[i][mj - 1] *= 2;
                    board[i][j] = 0;
                    canMerge = false;
                }
                else
                {
                    board[i][mj] = board[i][j];
                    if (j > mj)
                    {
                        board[i][j] = 0;
                    }

                    mj++;
                    canMerge = true;
                }
            }
        }
    };

    int res = 0;

    function<void(int)> solveRec = [&](int cnt)
    {
        if (cnt == 5)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    res = max(res, board[i][j]);
                }
            }
            return;
        }

        vector<vector<int>> prevBoard(N, vector<int>(N));

        for (int r = 0; r < 4; r++)
        {
            rotate90();
            prevBoard = board;
            pushLeft();
            solveRec(cnt + 1);
            board = prevBoard;
        }
    };

    solveRec(0);

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
