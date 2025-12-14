#include <bits/stdc++.h>
using namespace std;

// 좌표압축, 투포인터(슬라이딩 윈도우)

int len;
vector<string> comp;
unordered_map<string, int> um_idx;

vector<int> solution(vector<string> gems) 
{
    len = gems.size();
    comp = gems;
    
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    
    int N = comp.size();
    for (int i = 0 ; i < N ; i++)
        um_idx[comp[i]] = i;
    
    int n = 0;
    vector<int> use_cnt(N);
    
    vector<int> ans(2);
    int mn_len = len + 1;
    
    for (int l = 0, r = 0 ; l < len ; l++)
    {
        while (r < len && n < N)
        {
            int idx_r = um_idx[gems[r++]];
            
            if (use_cnt[idx_r] == 0)
                n++;
            use_cnt[idx_r]++;
        }
        
        if (n == N && r - l < mn_len)
        {
            ans[0] = l + 1;
            ans[1] = r;
            mn_len = r - l;
        }
        
        int idx_l = um_idx[gems[l]];
        use_cnt[idx_l]--;
        if (use_cnt[idx_l] == 0)
            n--;
    }
    
    return ans;
}