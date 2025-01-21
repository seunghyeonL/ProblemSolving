#include <string>
#include <vector>
#include <utility>

using namespace std;

bool isValid(int i, int j, int n)
{
    return i < n && j < n;
}

vector<int> solution(int n)
{
    vector<int> answer;
    vector<pair<int, int>> direction{{1, 0}, {0, 1}, {-1, -1}};
    vector<vector<int>> board(1001, vector<int>(1001, 0));

    int cnt = 0;
    int dirIdx = 0;
    auto curDirection = direction[0];
    int curI = 0;
    int curJ = 0;

    while (true)
    {
        board[curI][curJ] = ++cnt;

        int nextI = curI + curDirection.first;
        int nextJ = curJ + curDirection.second;

        if (board[nextI][nextJ] || !isValid(nextI, nextJ, n))
        {
            curDirection = direction[(++dirIdx) % 3];
            nextI = curI + curDirection.first;
            nextJ = curJ + curDirection.second;
            if (board[nextI][nextJ] || !isValid(nextI, nextJ, n))
            {
                break;
            }
        }

        curI = nextI;
        curJ = nextJ;
    }

    for (auto line : board)
    {
        for (auto n : line)
        {
            if (n == 0)
            {
                break;
            }
            answer.push_back(n);
        }
    }

    return answer;
}