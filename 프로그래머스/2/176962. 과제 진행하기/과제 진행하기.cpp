#include <bits/stdc++.h>
using namespace std;

// 24h == 1440m
// 분당 시뮬레이션 하면서
// 끊기는 과제를 stack에 넣고 관리 (최근에 멈춘 과제부터 시작하기 때문)

int get_minute(const string& str)
{
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    
    return h * 60 + m;
}

vector<string> solution(vector<vector<string>> _plans) 
{
    int N = _plans.size();
    
    // start, playtime, name
    vector<tuple<int, int, string>> plans(N);
    
    for (int i = 0 ; i < N ; i++)
    {
        const auto& plan = _plans[i];
        
        int st = get_minute(plan[1]);
        int pt = stoi(plan[2]);
        string name = plan[0];
        
        plans[i] = {st, pt, name};
    }
    
    sort(plans.begin(), plans.end());
    
    // 이름, 남은 시간
    stack<pair<string, int>> stk;
    vector<string> ans;
    
    for (int pi = 0, t = 0 ; pi < N || !stk.empty() ; t++)
    {
        if (!stk.empty())
        {
            auto& [cn, rt] = stk.top();

            if (--rt == 0)
            {
                ans.push_back(cn);
                stk.pop();
            }
        }
        
        if (pi < N)
        {
            const auto& [st, pt, name]  = plans[pi];
            
            if (t == st)
            {
                stk.emplace(name, pt);
                pi++;
            }
        }
    }
    
    return ans;
}