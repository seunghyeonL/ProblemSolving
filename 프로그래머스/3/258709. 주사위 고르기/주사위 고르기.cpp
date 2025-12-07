#include <bits/stdc++.h>
using namespace std;

// 절반씩 나누는 모든 경우에 대해
// 나올수 있는 A의 점수 마다 그보다 작은 B의 점수 개수를 이분탐색

int N;
vector<vector<int>> dice_e;

void rec(int sc, int idx, vector<int> &sc_arr,
         const vector<int> &dice_idxs)
{
    if (idx == N / 2)
    {
        sc_arr.push_back(sc);
        return;
    }
    
    const vector<int> &cur_dice = dice_e[dice_idxs[idx]];

    for (int i = 0; i < 6; i++)
    {
        rec(sc + cur_dice[i], idx + 1, sc_arr, dice_idxs);
    }
}

vector<int> solution(vector<vector<int>> dice) 
{
    N = dice.size();
    dice_e = dice;
    
    vector<bool> mask(N);
    fill(mask.begin(), mask.begin() + N / 2, true);
    
    int mx_a_win_num = 0;
    vector<int> ans;
    
    do
    {
        vector<int> a_dice_idxs;
        vector<int> b_dice_idxs;
        
        // A가 고른 다이스
        for (int i = 0 ; i < N ; i++)
        {
            if (mask[i])
            {
                a_dice_idxs.push_back(i);
            }
        }
        
        // B가 고른 다이스
        for (int i = 0 ; i < N ; i++)
        {
            if (!mask[i])
            {
                b_dice_idxs.push_back(i);
            }
        }
        
        vector<int> a_score;
        vector<int> b_score;
        
        rec(0, 0, a_score, a_dice_idxs);
        rec(0, 0, b_score, b_dice_idxs);
        
        sort(b_score.begin(), b_score.end());
        
        int a_win_num = 0;
        for (int a_sc : a_score)
        {
            a_win_num += lower_bound(b_score.begin(), b_score.end(), a_sc) - b_score.begin();
        }
        
        if (a_win_num > mx_a_win_num)
        {
            mx_a_win_num = a_win_num;
            ans = a_dice_idxs;
        }
        
    } while(prev_permutation(mask.begin(), mask.end()));
    
    for (int i = 0 ; i < N / 2 ; i++) 
        ans[i]++;
    
    sort(ans.begin(), ans.end());
    
    return ans;
}