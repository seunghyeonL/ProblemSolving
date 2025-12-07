#include <bits/stdc++.h>
using namespace std;

int op_start_time;
int op_end_time;
int video_len_time;

int get_time(const string& str)
{
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
}

void operate_next(int& ct)
{
    if (ct >= op_start_time && ct < op_end_time) 
    {
        ct = op_end_time + 10;
        return;
    }
    
    int nt = min(ct + 10, video_len_time);
    
    if (nt >= op_start_time && nt < op_end_time) 
    {
        ct = op_end_time;   
        return;
    }
    
    ct = nt;
}

void operate_prev(int& ct)
{
    if (ct >= op_start_time && ct < op_end_time)
    {
        ct = op_end_time;
        return;
    }
        
    int nt = max(ct - 10, 0);
    
    if (nt >= op_start_time && nt < op_end_time) 
    {
        ct = op_end_time;   
        return;
    }
    
    ct = nt;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) 
{
    op_start_time = get_time(op_start);
    op_end_time = get_time(op_end);
    video_len_time = get_time(video_len);
    
    int ct = get_time(pos);
    
    for (const auto& command : commands)
    {
        if (command == "next") operate_next(ct);
        else if (command == "prev") operate_prev(ct);
    }
    
    stringstream ss;
    
    string m = to_string(ct / 60);
    string s = to_string(ct % 60);
    
    if (m.size() == 1) ss << '0';
    ss << m << ':';
    if (s.size() == 1) ss << '0';
    ss << s;
    
    return ss.str();
}