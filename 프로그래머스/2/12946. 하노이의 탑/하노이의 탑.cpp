#include <string>
#include <vector>
#include <stack>
#include <functional>

using namespace std;

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;

    vector<stack<int>> board(3, stack<int>());

    for (int i = n - 1; i >= 0; --i)
    {
        board[0].push(i);
    }

    function<void(int, int)> move = [&](int start, int dest) -> void
    {
        // cout << "start: " << start << " dest: " << dest << '\n';
        int front = board[start].top();
        // cout << " front: " << front << '\n';
        board[start].pop();
        board[dest].push(front);

        answer.push_back(vector<int>{start + 1, dest + 1});
    };

    function<void(int, int, int)> moveHill = [&](int start, int dest,
                                                 int height) -> void
    {
        int tmp;
        for (int i = 0; i < 3; i++)
        {
            if (i != start && i != dest)
            {
                tmp = i;
                break;
            }
        }
        if (height > 1)
        {
            moveHill(start, tmp, height - 1);
            move(start, dest);
            moveHill(tmp, dest, height - 1);
        }
        else
        {
            move(start, dest);
        }
    };

    moveHill(0, 2, n);

    return answer;
}
