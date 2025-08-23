#include <string>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = 0;
    int size1 = queue1.size();
    int size2 = queue2.size();
    int size = size1 + size2;

    vector<int> v;
    v.reserve(size);

    for (int i : queue1)
    {
        v.push_back(i);
    }

    for (int i : queue2)
    {
        v.push_back(i);
    }

    int idx1 = 0, idx2 = size1;
    ll sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    ll sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);

    while (idx1 <= size || idx2 <= size + size1)
    {
        if (sum1 == sum2)
            break;
        else if (sum1 > sum2)
        {
            if (idx1 == size)
            {
                answer = -1;
                break;
            }

            sum1 -= v[idx1];
            sum2 += v[idx1];
            idx1++;
            answer++;
        }
        else
        {
            if (idx2 == size + size1)
            {
                answer = -1;
                break;
            }

            sum1 += v[idx2 % size];
            sum2 -= v[idx2 % size];
            idx2++;
            answer++;
        }
    }

    return answer;
}
