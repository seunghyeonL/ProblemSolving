#include <string>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    priority_queue<int, vector<int>, less<int>> pq(less<int>(), priorities);

    list<pair<int, int>> pl;

    for (int i = 0; i < priorities.size(); i++)
    {
        pl.push_back({i, priorities[i]});
    }

    while (pl.size() > 0)
    {
        auto front = pl.front();
        pl.pop_front();
        if (front.second == pq.top())
        {
            ++answer;
            pq.pop();
            if (front.first == location)
            {
                break;
            }
        }
        else
        {
            pl.push_back(front);
        }
    }

    return answer;
}
