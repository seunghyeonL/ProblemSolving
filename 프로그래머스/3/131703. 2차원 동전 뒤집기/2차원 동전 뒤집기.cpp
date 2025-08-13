#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target)
{
    int answer = 0;

    int INF = 1e9;
    int N = target.size();
    int M = target[0].size();

    auto solve = [&](int r0Flip)
    {
        int flips = r0Flip;

        vector<int> cFlips(M);

        for (int i = 0; i < M; i++)
        {
            // b ^ r0Flip ^ c == t
            // c == r0Flip ^ b ^ t
            cFlips[i] = r0Flip ^ beginning[0][i] ^ target[0][i];
            flips += cFlips[i];
        }

        for (int i = 1; i < N; i++)
        {
            int rFlip = beginning[i][0] ^ target[i][0] ^ cFlips[0];

            bool failed = false;
            for (int j = 1; j < M; j++)
            {
                if (beginning[i][j] ^ rFlip ^ cFlips[j] != target[i][j])
                {
                    failed = true;
                    flips = INF;
                    break;
                }
            }

            if (!failed)
                flips += rFlip;
            else
                break;
        }

        return flips;
    };

    answer = min(solve(0), solve(1));

    return answer == INF ? -1 : answer;
}

