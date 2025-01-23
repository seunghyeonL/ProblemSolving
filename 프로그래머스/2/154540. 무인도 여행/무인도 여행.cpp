#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(int i, int j, int N, int M)
{
    return i >= 0 && i < N && j >= 0 && j < M;
}

void dfs(int curI, int curJ, const vector<string> &maps,
         vector<vector<bool>> &isVisited, int &result)
{
    isVisited[curI][curJ] = true;
    // cout << "b result: " << result << '\n';
    result += maps[curI][curJ] - '0';
    // cout << "maps[curI][curJ]: " << maps[curI][curJ] << '\n';
    // cout << "result: " << result << '\n';
    vector<pair<int, int>> direction{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    for (auto [diffI, diffJ] : direction)
    {
        int nextI = curI + diffI;
        int nextJ = curJ + diffJ;

        if (isValid(nextI, nextJ, maps.size(), maps[0].size()) &&
            !isVisited[nextI][nextJ])
        {
            dfs(nextI, nextJ, maps, isVisited, result);
        }
    }
}

vector<int> solution(vector<string> maps)
{
    vector<int> answer;
    int N = maps.size();
    int M = maps[0].size();
    vector<vector<bool>> isVisited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            isVisited[i][j] = maps[i][j] == 'X' ? true : false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!isVisited[i][j])
            {
                int result = 0;
                dfs(i, j, maps, isVisited, result);
                answer.push_back(result);
            }
        }
    }

    if (answer.empty())
    {
        answer.push_back(-1);
        return answer;
    }

    sort(answer.begin(), answer.end());

    return answer;
}
