#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights)
{
    long long answer = 0;

    sort(weights.begin(), weights.end()); 

    unordered_map<int, int> weightCount;
    for (int weight : weights)
        weightCount[weight]++;

    function<void(int, int)> findCouple = [&](int load1, int load2)
    {
        for (auto &[weight, count] : weightCount)
        {
            long long target = (long long)weight * load2 / load1;
            if ((long long)weight * load2 % load1 != 0)
                continue; 

            if (weightCount.find(target) != weightCount.end())
            {
                if (weight == target)
                {
                    // load 1 1 경우
                    answer += (long long)count * (count - 1) / 2;
                }
                else if (weight < target)
                {
                    // 다른 load 경우
                    answer += (long long)count * weightCount[target];
                }
            }
        }
    };

    findCouple(2, 4);
    findCouple(3, 4);
    findCouple(2, 3);
    findCouple(1, 1);

    return answer;
}