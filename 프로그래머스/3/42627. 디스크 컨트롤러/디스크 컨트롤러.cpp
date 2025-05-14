#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> jobs) {
    using Task = tuple<int, int, int>;
    int answer = 0;
    int size = jobs.size();

    // [요청 시각, 소요 시간]
    // 우선순위 : 소요시간 짧음, 요청 시각 빠름, 번호가 작음

    struct Priority
    {
        bool operator()(const Task& t1, const Task& t2) const
        {
            auto [id1, callTime1, needTime1] = t1;
            auto [id2, callTime2, needTime2] = t2;

            if (needTime1 != needTime2)
            {
                return needTime1 > needTime2;
            }

            if (callTime1 != callTime2)
            {
                return callTime1 > callTime2;
            }

            return id1 > id2;
        }
    };
    
    priority_queue<Task, vector<Task>, Priority> taskQueue;

    sort(jobs.begin(), jobs.end(), [](const auto& t1, const auto& t2) { return t1[0] < t2[0]; });

    bool isTasking = false;
    Task curTask {-1, -1, -1}; 
    int taskIdx = 0;
    int time = -1;
    
    
    while (taskIdx < size || !taskQueue.empty() || isTasking)
    {
        time++;

        while (taskIdx < size && jobs[taskIdx][0] == time)
        {
            taskQueue.emplace(taskIdx, jobs[taskIdx][0], jobs[taskIdx][1]);
            taskIdx++;
        }
        
        if (isTasking)
        {
            auto& [curTaskIdx, curTaskCallTime, curTaskNeedTime] = curTask;

            if (--curTaskNeedTime == 0)
            {
                isTasking = false;
                answer += time - curTaskCallTime;
            }
        }
        
        if (!isTasking)
        {
            if (!taskQueue.empty())
            {
                auto nextTask = taskQueue.top();
                taskQueue.pop();
                curTask = nextTask;
                isTasking = true;
            }
        }
    }
    
    return answer/size;
}