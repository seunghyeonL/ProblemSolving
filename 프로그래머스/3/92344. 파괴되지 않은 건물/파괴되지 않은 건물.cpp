#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;

    /*
        면적의 변화량을 네 점의 변화로 표현한 후 합하고 구간합으로 복원
    */

    int N = board.size();
    int M = board[0].size();

    vector<vector<int>> mask(N, vector<int>(M));

    auto isValid = [&](int x, int y)
    { return x >= 0 && x < N && y >= 0 && y < M; };

    auto useSkill = [&](int r1, int c1, int r2, int c2, int d)
    {
        mask[r1][c1] += d;
        if (isValid(r1, c2 + 1))
            mask[r1][c2 + 1] -= d;
        if (isValid(r2 + 1, c1))
            mask[r2 + 1][c1] -= d;
        if (isValid(r2 + 1, c2 + 1))
            mask[r2 + 1][c2 + 1] += d;
    };

    for (auto sk : skill)
    {
        int t = sk[0];
        int r1 = sk[1];
        int c1 = sk[2];
        int r2 = sk[3];
        int c2 = sk[4];
        int d = sk[5];

        d *= (t == 1 ? -1 : 1);

        useSkill(r1, c1, r2, c2, d);
    }

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            if (c > 0)
                mask[r][c] += mask[r][c - 1];
        }
    }

    for (int c = 0; c < M; c++)
    {
        for (int r = 0; r < N; r++)
        {
            if (r > 0)
                mask[r][c] += mask[r - 1][c];
        }
    }

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            if (board[r][c] + mask[r][c] > 0)
                answer++;
        }
    }

    return answer;
}