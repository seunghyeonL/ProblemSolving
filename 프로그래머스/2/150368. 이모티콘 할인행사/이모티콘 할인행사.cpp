#include <bits/stdc++.h>
using namespace std;

// 각 이모티콘의 할인율 경우의 수를 완전탐색 => 4^7
// 최적 결과 보관

int N;
vector<vector<int>> U;
vector<int> E;

// idx : E idx, dcs : idx별 할인율, ans : 최대 플러스 가입, 그때 최대 판매액
void rec(int idx, vector<int>& dcs, pair<int, int>& ans)
{
    if (idx == N)
    {
        auto& [ans_a, ans_b] = ans;
        int a = 0, b = 0; // 플러스 가입자 수, 총 판매액
        
        for (const auto& user : U)
        {
            int u_dc = user[0]; // 구매 할인율
            int u_plus = user[1]; // 플러스 가입 가격

            int sum_price = 0;
            
            for (int i = 0 ; i < N ; i++)
            {
                int price = E[i];
                int dc = dcs[i];
            
                if (u_dc <= dc)
                    sum_price += price * (100 - dc) / 100;
            }
            
            if (sum_price >= u_plus)
            {
                a++;
            }
            else
            {
                b += sum_price;
            }
        }
        
        if (ans_a < a)
        {
            ans_a = a;
            ans_b = b;
        }
        else if (ans_a == a && ans_b < b)
        {
            ans_b = b;
        }
        
        return;
    }
    
    for (int dc : {10, 20, 30, 40})
    {
        dcs[idx] = dc;
        rec(idx + 1, dcs, ans);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) 
{
    N = emoticons.size();
    U = users;
    E = emoticons;
    
    vector<int> dcs(N);
    pair<int, int> ans;
    
    rec(0, dcs, ans);
    
    return vector<int>{ans.first, ans.second};
}