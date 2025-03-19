#include <string>
#include <vector>
#include <functional>
#include <utility>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<int> info)
{
    int maxDiff = 0;
    vector<int> answer{-1};
    vector<int> apeachInfo(info.begin(), info.end());
    vector<int> lionInfo(11, 0);

    auto calculateScore = [&]() -> pair<int, int>
    {
        int lionScore = 0;
        int apeachScore = 0;

        for (int i = 0; i < 11; i++)
        {
            if (lionInfo[i] > apeachInfo[i])
                lionScore += 10 - i;
            else if (apeachInfo[i] > 0)
                apeachScore += 10 - i;
        }
        return {lionScore, apeachScore};
    };

    function<void(int, int)> dfs = [&](int curIdx, int shootCnt) -> void
    {
        if(shootCnt == n)
        {
            auto [lionScore, apeachScore] = calculateScore();
            
            if(maxDiff < lionScore - apeachScore)
            {
                maxDiff = lionScore - apeachScore;
                answer = lionInfo;
            }
            else if(maxDiff == lionScore - apeachScore)
            {
                for(int i = 10 ; i >= 0 ; i--)
                {
                    if(answer[i] > lionInfo[i]) return;
                    else if(answer[i] < lionInfo[i])
                    {
                        answer = lionInfo;
                        break;
                    }
                    
                }   
            }
            return;
        }
        
        for(int i = curIdx ; i <= 10 ; i++)
        {
            int arrowNum = apeachInfo[i] + 1;
            if(arrowNum > n - shootCnt) {
                if(i < 10) continue;
                else arrowNum = n - shootCnt;
            }
            
            lionInfo[i] = arrowNum;
            dfs(i + 1, shootCnt + arrowNum);
            lionInfo[i] = 0;
        }
    };

    dfs(0, 0);

    return answer;
}
