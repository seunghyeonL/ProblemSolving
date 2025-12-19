#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    초기 상태 - o
    경계 처리 - o
    이벤트 순서
    오버플로우 - o
*/

vector<pair<ll, ll>> star_pos;

vector<string> solution(vector<vector<int>> line) 
{
    int N = line.size();
    
    for (int i = 0 ; i < N ; i++)
    {
        for (int j = i + 1 ; j < N ; j++)
        {
            ll a = line[i][0];
            ll b = line[i][1];
            ll e = line[i][2];
            
            ll c = line[j][0];
            ll d = line[j][1];
            ll f = line[j][2];
            
            ll D = a * d - b * c;
            ll A = b * f - e * d;
            ll B = e * c - a * f;
            
            if (D == 0)
                continue;
            
            if (A % D != 0 || B % D != 0)
                continue;
            
            star_pos.emplace_back(A / D, B / D);
            
        }
    }
    
    ll mn_x = 1e18;
    ll mn_y = 1e18;
    ll mx_x = -1e18;
    ll mx_y = -1e18;
    
    for (auto [x, y] : star_pos)
    {
        mn_x = min(mn_x, x);
        mx_x = max(mx_x, x);
        mn_y = min(mn_y, y);
        mx_y = max(mx_y, y);
    }
    
    int sz_x = mx_x - mn_x + 1;
    int sz_y = mx_y - mn_y + 1;
    
    // x, y 반전
    vector<string> ans(sz_y, string(sz_x, '.'));
    
    for (auto [x, y] : star_pos)
    {
        ans[y - mn_y][x - mn_x] = '*';
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}