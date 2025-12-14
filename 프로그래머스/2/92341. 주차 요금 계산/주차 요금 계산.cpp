#include <bits/stdc++.h>
using namespace std;

// 24 * 60 * 10000 = 14400000 -> int 

unordered_map<int, int> um_in; // 차량번호, 입차시간
unordered_map<int, int> um_acc; // 차량번호, 누적 주차 시간

int bt, bc, pt, pc;

int get_time(const string& time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    um_in.clear();
    um_acc.clear();
    
    bt = fees[0];
    bc = fees[1];
    pt = fees[2];
    pc = fees[3];
    
    for (const string& record : records)
    {
        stringstream ss(record);
        
        string time;
        string cn_s;
        string type;
        
        ss >> time >> cn_s >> type;
        
        int cn = stoi(cn_s);
        
        if (type == "IN")
        {
            um_in[cn] = get_time(time);
        }
        if (type == "OUT")
        {
            um_acc[cn] += get_time(time) - um_in[cn];
            um_in.erase(cn);
        }
    }

    for (auto [cn, t_in] : um_in)
    {
        um_acc[cn] += get_time("23:59") - t_in;
    }
    
    vector<pair<int, int>> tmp(um_acc.begin(), um_acc.end());
    sort(tmp.begin(), tmp.end());
    
    vector<int> answer;
    for (auto& [cn, time] : tmp)
    {
        int fee = bc;
        time -= bt;
        
        if (time > 0)
        {
            int n = time / pt;
            if (time % pt > 0)
                n++;
            
            fee += pc * n;
        }
        
        answer.push_back(fee);
    }
    
    return answer;
}