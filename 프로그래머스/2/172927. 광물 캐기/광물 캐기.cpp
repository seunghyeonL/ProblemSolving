#include <bits/stdc++.h>
using namespace std;

// 곡괭이마다 광물에 따른 피로도 부여
// 곡괭이마다 5개까지 캘 수 있음

// 사용할 수 있는 곡괭이중 아무거나 하나를 선택해 광물을 캡니다.
// 한 번 사용하기 시작한 곡괭이는 사용할 수 없을 때까지 사용합니다.
// 광물은 주어진 순서대로만 캘 수 있습니다.
// 광산에 있는 모든 광물을 캐거나, 더 사용할 곡괭이가 없을 때까지 광물을 캡니다.

// 피로도 최소화

// 총 15개 곡괭이 -> 756756 순서조합
// -> 완전탐색

const int INF = 1e9;

int W[3][3]
{
    {1, 1, 1},
    {5, 1, 1},
    {25, 5, 1},
};

unordered_map<string, int> m_ns
{
    {"diamond", 0},
    {"iron", 1},
    {"stone", 2},
};

const vector<string> comp{"diamond", "iron", "stone"};

int solution(vector<int> picks, vector<string> minerals) 
{
    int N = minerals.size();
    
    vector<int> mask(accumulate(picks.begin(), picks.end(), 0));
    fill(mask.begin(), mask.begin() + picks[0], 0);
    fill(mask.begin() + picks[0], mask.begin() + picks[0] + picks[1], 1);
    fill(mask.begin() + picks[0] + picks[1], mask.end(), 2);
    
    int ans = INF;
    do
    {
        int cur_ans = 0;
        int m_idx = 0;
        for (int c_pick_idx : mask)
        {
            for (int i = 0 ; i < 5 ; i++)
            {
                int m_n = m_ns[minerals[m_idx++]];
                cur_ans += W[c_pick_idx][m_n];
                
                if (m_idx == N)
                    break;
            }
            
            if (m_idx == N)
                break;
        }
        
        ans = min(ans, cur_ans);
    } while(next_permutation(mask.begin(), mask.end()));
    
    return ans;
}