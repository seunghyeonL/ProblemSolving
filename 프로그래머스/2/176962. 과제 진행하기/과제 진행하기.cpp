#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

vector<string> strSplit(string str, char seperator = ' ')
{
    vector<string> result;

    string buffer{};

    for (char chr : str)
    {
        if (chr == seperator)
        {
            result.push_back(buffer);
            buffer.clear();
            continue;
        }

        buffer.push_back(chr);
    }

    if (!buffer.empty())
    {
        result.push_back(buffer);
    }

    return result;
}

vector<string> solution(vector<vector<string>> plans) {
    struct Plan 
    {
        string name;
        int start;
        int playTime;

        bool operator<(const Plan& rhs) const
        {
            return start > rhs.start;
        }
    };

    vector<string> answer;
    int size = plans.size();
    
    priority_queue<Plan> q;
    stack<Plan> s;
    
    for(auto plan : plans)
    {
        string name = plan[0];
        int playTime = stoi(plan[2]);
        string time = plan[1];
        auto splitedTime = strSplit(time, ':');
        
        int start = stoi(splitedTime[0]) * 60 + stoi(splitedTime[1]);
        
        q.push({name, start, playTime});
    }
    
    Plan curPlan = q.top();
    int curTime = curPlan.start;
    q.pop();

    // Prints<vector<string>> prints;
    
    while (!q.empty() || !s.empty())
    {
        // prints(answer);
        auto& [curName, curStart, curPlayTime] = curPlan;
        // cout << "cur: " << curName << " " << curTime << " " << curPlayTime << '\n';
            
        if (!q.empty())
        {
            Plan nextPlan = q.top();
            auto& [nextName, nextStart, nextPlayTime] = nextPlan;
            // cout << "next: " << nextName << " " << nextStart << " " << nextPlayTime << '\n';
            if (curTime + curPlayTime > nextStart)
            {
                curPlayTime = curTime + curPlayTime - nextStart;
                curTime = nextStart;
                
                s.push(curPlan);
                curPlan = nextPlan;
                q.pop();
            }
            else
            {
                if (!s.empty())
                {
                    curTime += curPlayTime;
                    answer.push_back(curName);
                
                    curPlan = s.top();
                    s.pop();
                }
                else
                {
                    curTime = nextStart;
                    answer.push_back(curName);
                
                    curPlan = nextPlan;
                    q.pop();
                }
            }
                
        }
        else if (!s.empty())
        {
            curTime += curPlayTime;
            answer.push_back(curName);
                
            curPlan = s.top();
            s.pop();
        }
    }

    answer.emplace_back(curPlan.name);

    
    return answer;
}