#include <bits/stdc++.h>
using namespace std;

int video_len;
int op_start;
int op_end;
int ct;

int to_second(const string& str)
{
    int m = stoi(str.substr(0, 2));
    int s = stoi(str.substr(3, 2));
    
    return m * 60 + s;
}

void skip_opening()
{
    if (ct >= op_start && ct <= op_end)
        ct = op_end;
}

void operate_next()
{
    skip_opening();
    
    ct = min(ct + 10, video_len);
    
    skip_opening();
}

void operate_prev()
{
    skip_opening();
    
    ct = max(ct - 10, 0);
    
    skip_opening();
}

string solution(string _video_len, string _pos, string _op_start, string _op_end, vector<string> commands) 
{
    video_len = to_second(_video_len);
    op_start = to_second(_op_start);
    op_end = to_second(_op_end);
    
    ct = to_second(_pos);
    
    for (const string& command : commands)
    {
        if (command == "next")
            operate_next();
        else
            operate_prev();
    }
    
    string m = to_string(ct / 60);
    string s = to_string(ct % 60);
    
    stringstream ss;
    
    if (m.size() == 1) 
        ss << '0';
    ss << m << ':';
    
    if (s.size() == 1)
        ss << '0';
    ss << s;
    
    return ss.str();
}