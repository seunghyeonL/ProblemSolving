#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k)
{
    int size = stones.size();

    /*
        건널 수 있는 사람이 n명 이라고 할때 가능한지 여부로 이분탐색
        n이 불가능한 n이면 n+1도 불가능
        n이 가능한 n이면 n-1도 가능

        각 요소에 n - 1 을 뺐을때 연속하는 0 이하인 개수 찾기
    */

    // n명이 다리를 건널 수 있는가?
    auto check = [&](int n)
    {
        int zeroCount = 0;

        for (int i = 0; i < size; i++)
        {
            if (stones[i] - (n - 1) <= 0)
                zeroCount++;
            else
                zeroCount = 0;

            if (zeroCount == k)
                return false;
        }

        return true;
    };

    int left = 1;
    int right = 1e9;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (check(mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return right;
}
