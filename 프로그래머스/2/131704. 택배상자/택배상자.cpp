#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> order)
{
    int size = order.size();

    queue<int> q;
    for (int i = 1; i <= size; i++)
    {
        q.push(i);
    }
    stack<int> s;
    int answer = 0;

    while (!q.empty() || !s.empty())
    {

        if (!q.empty() && !s.empty())
        {
            int cur1 = q.front();
            int cur2 = s.top();

            // cout << "q, s 다있음" << '\n';
            // cout << "cur1: " << cur1 << '\n';
            // cout << "cur2: " << cur2 << '\n';
            // cout << "order[answer]: " << order[answer] << '\n';

            if (cur1 == order[answer])
            {
                ++answer;
                q.pop();
            }
            else if (cur2 == order[answer])
            {
                ++answer;
                s.pop();
            }
            else
            {
                s.push(cur1);
                q.pop();
            }
        }
        else if (!q.empty())
        {
            int cur = q.front();
            q.pop();

            // cout << "q 있음" << '\n';
            // cout << "cur: " << cur << '\n';
            // cout << "order[answer]: " << order[answer] << '\n';

            if (cur == order[answer])
            {
                ++answer;
            }
            else
            {
                s.push(cur);
            }
        }
        else if (!s.empty())
        {
            int cur = s.top();
            s.pop();

            // cout << "s 있음" << '\n';
            // cout << "cur: " << cur << '\n';
            // cout << "order[answer]: " << order[answer] << '\n';

            if (cur == order[answer])
            {
                ++answer;
            }
            else
            {
                break;
            }
        }
    }

    return answer;
}