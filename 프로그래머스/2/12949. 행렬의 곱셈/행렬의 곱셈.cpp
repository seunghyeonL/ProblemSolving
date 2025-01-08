#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    int sizei = arr1.size();
    int sizek = arr2.size();
    int sizej = arr2[0].size();
    vector<vector<int>> answer(sizei, vector<int>(sizej, 0));

    for (int i = 0; i < sizei; i++)
    {
        for (int j = 0; j < sizej; j++)
        {
            int mul = 0;
            for (int k = 0; k < sizek; k++)
            {
                mul += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = mul;
        }
    }

    return answer;
}
