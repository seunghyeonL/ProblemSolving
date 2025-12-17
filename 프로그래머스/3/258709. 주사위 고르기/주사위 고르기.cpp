#include <bits/stdc++.h>
using namespace std;

// 10C5 = 252;
// 6^5 = 7776
// A 조합에서 이기는 경우를 체크, 이기는 경우가 가장 많은 조합이 정답
// A 조합에서 나올 수 있는 점수 마다 B 조합에서 나올 수 있는 점수가 더 작은 경우를 이분탐색

int N;
vector<vector<int>> dice;

void dfs(int idx, int acc, const vector<int>& idxs, vector<int>& res)
{
    if (idx == N / 2)
    {
        res.push_back(acc);
        return;
    }
    
    int dice_idx = idxs[idx];
    vector<int>& c_dice = dice[dice_idx];
    
    for (int n : c_dice)
    {
        dfs(idx + 1, acc + n, idxs, res);
    }
}

vector<int> solution(vector<vector<int>> _dice) 
{
    dice = _dice;
    N = dice.size();
    
    vector<bool> mask(N); // A가 고른 주사위 idx
    fill(mask.begin(), mask.begin() + N / 2, true);
   
    int mx_win_num = 0;
    vector<int> ans;
    
    do
    {
        vector<int> A_idxs;
        vector<int> B_idxs;
        
        vector<int> A; // 가능한 A 점수
        vector<int> B; // 가능한 B 점수
        
        for (int i = 0 ; i < N ; i++)
        {
            if (mask[i])
                A_idxs.push_back(i);
            else 
                B_idxs.push_back(i);
        }
        
        dfs(0, 0, A_idxs, A);
        dfs(0, 0, B_idxs, B);
        
        sort(B.begin(), B.end());
        int c_win_num = 0;
        
        for (int av : A)
        {
            // b점수가 현재 A점수보다 더 높아지는 최소 idx
            // == A점수보다 작은 B점수 개수
            int lbi = lower_bound(B.begin(), B.end(), av) - B.begin();
            c_win_num += lbi;
        }
        
        if (mx_win_num < c_win_num)
        {
            mx_win_num = c_win_num;
            ans = A_idxs;
        }
        
    } while(prev_permutation(mask.begin(), mask.end()));
    
    for (int& el : ans)
        el++;
    
    return ans;
}