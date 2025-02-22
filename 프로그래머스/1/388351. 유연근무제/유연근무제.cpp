#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int size = schedules.size();
    
    deque<int> validDays { true, true, true, true, true, false, false };
    for(int i = 0 ; i < startday - 1 ; i++)
    {
        int front = validDays.front();
        validDays.push_back(front);
        validDays.pop_front();
    }
    
    auto makeMinute = [](int time){ 
        return time / 100 * 60 + time % 100;
    };
    
    
    for(int i = 0 ; i < size ; i++)
    {
        int scheduleTime = makeMinute(schedules[i]);
        
        bool successFlag = true;
        for(int j = 0 ; j < 7 ; j++)
        {
            if(!validDays[j]) continue;
            
            int startWorkTime = makeMinute(timelogs[i][j]);
            if(startWorkTime > scheduleTime + 10) {
                successFlag = false;
                break;
            }
        }
        
        if(successFlag) answer++;
    }
    
    return answer;
}