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

vector<string> solution(vector<vector<string>> plans) 
{
    int N = plans.size();
    
    sort(plans.begin(), plans.end(), [](const auto& a, const auto& b){
        return a[1] < b[1];
    });
    
    // 이름, 남은 시간
    stack<pair<string, int>> st;
    vector<string> ans;
    
    
    for (int pi = 0, t = 0 ; pi < N || !st.empty() ; t++)
    {
        if (!st.empty())
        {
            auto& [cn, rt] = st.top();

            if (--rt == 0)
            {
                ans.push_back(cn);
                st.pop();
            }
        }
        
        if (pi < N)
        {
            const auto& plan = plans[pi];
            if (t == get_minute(plan[1]))
            {
                st.emplace(plan[0], stoi(plan[2]));
                pi++;
            }
        }
    }
    
    return ans;
}