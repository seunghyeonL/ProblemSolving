#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer{-1, -1};
    int size = sequence.size();
    int answerLength{size + 1};

    vector<int> partialSum(size + 1, 0);

    for (int i = 0; i < size; i++)
    {
        partialSum[i + 1] = partialSum[i] + sequence[i];
    }
    // prints(partialSum);

    for (int i = 0; i < size; i++)
    {
        int begin = i;
        int end = size - 1;
        while (begin <= end)
        {
            int mid = (begin + end) / 2;

            if (partialSum[mid + 1] - partialSum[i] > k)
            {
                end = mid - 1;
            }
            else if (partialSum[mid + 1] - partialSum[i] == k)
            {
                int curLength = mid + 1 - i;
                if (answerLength > curLength)
                {
                    answer[0] = i;
                    answer[1] = mid;
                    answerLength = curLength;
                }
                break;
            }
            else
            {
                begin = mid + 1;
            }
        }
    }

    return answer;
}
