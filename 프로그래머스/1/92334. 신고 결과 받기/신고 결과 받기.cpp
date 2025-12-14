#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
int N;
unordered_map<string, int> id_idx;
vector<int> picked[NMX];
int mail_num[NMX];

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    N = id_list.size();    
    for (int i = 0 ; i < N ; i++)
        id_idx[id_list[i]] = i;
    
    memset(mail_num, 0, sizeof(mail_num));
    
    for (const string& str : report)
    {
        stringstream ss(str);
        string s, e;
        ss >> s >> e;
        
        int sv = id_idx[s];
        int ev = id_idx[e];
        
        picked[ev].push_back(sv);
    }
    
    for (int i = 0 ; i < N ; i++)
    {
        auto& v = picked[i];
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    
    for (int i = 0 ; i < N ; i++)
    {
        if (picked[i].size() >= k)
        {
            for (int el : picked[i])
            {
                mail_num[el]++;
            }
        }
    }
    
    vector<int> answer;
    
    for (int i = 0 ; i < N ; i++)
    {
        answer.push_back(mail_num[i]);
    }
    
    return answer;
}