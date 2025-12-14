#include <bits/stdc++.h>
using namespace std;

// 투포인터

int len;
vector<string> comp;

int get_idx(const string& gem)
{
    return lower_bound(comp.begin(), comp.end(), gem) - comp.begin();
}

vector<int> solution(vector<string> gems) 
{
    len = gems.size();
    comp = gems;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    
    int N = comp.size();
    int n = 0;
    vector<int> use_cnt(N);
    
    vector<int> ans(2);
    int mn_len = len + 1;
    
    for (int l = 0, r = 0 ; l < len ; l++)
    {
        while (r < len && n < N)
        {
            int idx_r = get_idx(gems[r++]);
            
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
        
        int idx_l = get_idx(gems[l]);
        use_cnt[idx_l]--;
        if (use_cnt[idx_l] == 0)
            n--;
    }
    
    return ans;
}