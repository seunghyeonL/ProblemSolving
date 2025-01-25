#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> board(rows + 1, vector<int>(columns + 1, 0));

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            board[i][j] = (i - 1) * columns + j;
        }
    }

    // for (int i = 0; i < board.size(); i++)
    // {
    //     prints(board[i]);
    // }
    // cout << '\n';

    enum MoveMode
    {
        RIGHT,
        DOWN,
        LEFT,
        UP
    };

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (auto query : queries)
    {
        int sX = query[0], sY = query[1];
        int dX = query[2], dY = query[3];

        vector<pair<int, int>> destinations{
            {sX, dY}, {dX, dY}, {dX, sY}, {sX, sY}};

        int curX = sX, curY = sY;
        int thisAnswer = rows * columns;

        MoveMode mMode = RIGHT;
        int tmp = 0;

        while (true)
        {
            swap(tmp, board[curX][curY]);
            if (tmp != 0)
            {
                thisAnswer = thisAnswer > tmp ? tmp : thisAnswer;
            }

            // cout << "curX: " << curX << " curY: " << curY
            //      << " value: " << board[curX][curY] << " Mode: " << mMode;

            // cout << " destination: " << destinations[mMode].first << " "
            //      << destinations[mMode].second << '\n';

            if (make_pair(curX, curY) == destinations[mMode])
            {
                // cout << "thisAnswer: " << thisAnswer << '\n';
                // cout << " destination: " << destinations[mMode].first << " "
                //      << destinations[mMode].second << '\n';
                if (mMode == UP)
                {
                    // cout << "thisAnswer: " << thisAnswer << '\n';
                    // cout << " destination: " << destinations[mMode].first <<
                    // " "
                    //      << destinations[mMode].second << '\n';
                    break;
                }
                mMode = MoveMode(int(mMode) + 1);
            }
            auto [diffX, diffY] = directions[mMode];
            curX += diffX;
            curY += diffY;
        }
        // cout << "thisAnswer: " << thisAnswer << '\n';
        answer.push_back(thisAnswer);
    }

    return answer;
}