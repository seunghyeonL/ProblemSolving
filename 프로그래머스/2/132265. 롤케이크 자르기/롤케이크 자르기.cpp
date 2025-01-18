#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping)
{
    int answer = 0;

    int size = topping.size();
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;

    for (int cur : topping)
    {
        auto it = m2.find(cur);
        if (it == m2.end())
        {
            m2.insert({cur, 1});
        }
        else
        {
            m2[cur]++;
        }
    }

    for (int cur : topping)
    {
        auto it1 = m1.find(cur);
        if (it1 == m1.end())
        {
            m1.insert({cur, 1});
        }
        else
        {
            m1[cur]++;
        }

        if (m2[cur] == 1)
        {
            m2.erase(cur);
        }
        else
        {
            m2[cur]--;
        }

        if (m1.size() == m2.size())
            answer++;
    }

    return answer;
}
