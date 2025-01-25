#include <string>
#include <vector>
#include <limits>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    int size = queue1.size();
    int answer = numeric_limits<int>::max();
    vector<long long> partialSum(size * 4 + 1);
    partialSum[0] = 0;
    long long sum = 0;

    for (int i = 0; i < size; i++)
    {
        partialSum[i + 1] = partialSum[i] + queue1[i];
    }

    for (int i = size; i < 2 * size; i++)
    {
        partialSum[i + 1] = partialSum[i] + queue2[i - size];
    }

    for (int i = 2 * size; i < 3 * size; i++)
    {
        partialSum[i + 1] = partialSum[i] + queue1[i - 2 * size];
    }

    for (int i = 3 * size; i < 4 * size; i++)
    {
        partialSum[i + 1] = partialSum[i] + queue2[i - 3 * size];
    }

    sum = partialSum[2 * size];
    // if (partialSum[size] * 2 == sum)
    // {
    //     return 0;
    // }
    // prints(partialSum);
    // cout << "sum: " << sum << '\n';

    for (int i = 0; i < 2 * size; i++)
    {
        int begin = size - 1 < i ? i : size - 1;
        int end = 2 * size - 1 + i;
        // cout << "i: " << i << '\n';

        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            // cout << "begin: " << begin << " end: " << end << " mid: " << mid
            //      << '\n';
            // cout << "checking value: " << partialSum[mid + 1] - partialSum[i]
            //      << '\n';
            if (partialSum[mid + 1] - partialSum[i] < sum / 2)
            {
                begin = mid + 1;
            }
            else if (partialSum[mid + 1] - partialSum[i] == sum / 2)
            {
                int curAnswer = i + mid - size + 1;
                // cout << "curAnser: " << curAnswer << '\n';
                // cout << "answer: " << answer << '\n';
                answer = curAnswer < answer ? curAnswer : answer;
                // cout << "answer: " << answer << '\n';
                break;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    if (answer == numeric_limits<int>::max())
    {
        answer = -1;
    }

    return answer;
}

