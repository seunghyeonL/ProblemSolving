#include <string>
#include <vector>
#include <functional>

using namespace std;

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;

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
            answer.push_back(vector<int>{start + 1, dest + 1});
            moveHill(tmp, dest, height - 1);
        }
        else
        {
            answer.push_back(vector<int>{start + 1, dest + 1});
        }
    };

    moveHill(0, 2, n);

    return answer;
}