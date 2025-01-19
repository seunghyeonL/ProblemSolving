#include <string>
#include <vector>

using namespace std;

int quad(vector<vector<int>> &arr, vector<int> &answer, int xBegin, int xEnd,
         int yBegin, int yEnd)
{
    if (xBegin == xEnd && yBegin == yEnd)
    {
        if (arr[xBegin][yBegin])
        {
            answer[1]++;
            return 1;
        }
        else
        {
            answer[0]++;
            return 0;
        }
    }

    int xMiddle = (xBegin + xEnd) / 2;
    int yMiddle = (yBegin + yEnd) / 2;

    int quad1 = quad(arr, answer, xBegin, xMiddle, yBegin, yMiddle);
    int quad2 = quad(arr, answer, xMiddle + 1, xEnd, yBegin, yMiddle);
    int quad3 = quad(arr, answer, xBegin, xMiddle, yMiddle + 1, yEnd);
    int quad4 = quad(arr, answer, xMiddle + 1, xEnd, yMiddle + 1, yEnd);

    if (quad1 == 1 && quad2 == 1 && quad3 == 1 && quad4 == 1)
    {
        answer[1] -= 3;
        return 1;
    }
    else if (quad1 == 0 && quad2 == 0 && quad3 == 0 && quad4 == 0)
    {
        answer[0] -= 3;
        return 0;
    }
    else
    {
        return -1;
    }
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer{0, 0};
    int size = arr.size();

    quad(arr, answer, 0, size - 1, 0, size - 1);

    return answer;
}