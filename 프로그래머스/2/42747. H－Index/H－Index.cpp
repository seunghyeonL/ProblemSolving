#include <string>
#include <vector>

using namespace std;

int pbinarySearch(int begin, int end, vector<int> &citations)
{
    if (begin >= end - 1)
    {
        return begin;
    }

    int answer{};
    int mid = (begin + end) / 2;
    int paperNum{};

    for (int n : citations)
    {
        if (n >= mid)
        {
            paperNum++;
        }
    }

    if (mid == paperNum)
    {
        answer = mid;
    }
    else if (mid < paperNum)
    {
        answer = pbinarySearch(mid, end, citations);
    }
    else
    {
        answer = pbinarySearch(begin, mid, citations);
    }
    return answer;
}

int solution(vector<int> citations)
{
    return pbinarySearch(0, 10000, citations);
}