#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    int size = queue1.size();
    int answerMax = size * 4;
    int answer = 0;

    deque<int> dq1(size);
    long long sum1 = 0;
    deque<int> dq2(size);
    long long sum2 = 0;
    for (int i = 0; i < size; i++)
    {
        sum1 += queue1[i];
        sum2 += queue2[i];
        dq1[i] = queue1[i];
        dq2[i] = queue2[i];
    }

    while (sum1 != sum2 && answer < answerMax)
    {
        if (sum1 < sum2)
        {
            int front2 = dq2.front();
            dq2.pop_front();
            dq1.push_back(front2);
            sum2 -= front2;
            sum1 += front2;
        }
        else
        {
            int front1 = dq1.front();
            dq1.pop_front();
            dq2.push_back(front1);
            sum1 -= front1;
            sum2 += front1;
        }
        answer++;
    }

    if (answer == answerMax)
    {
        answer = -1;
    }
    return answer;
}

