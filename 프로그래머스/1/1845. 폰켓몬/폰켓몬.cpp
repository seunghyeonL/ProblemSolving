#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s;
    
    for (int num : nums)
    {
        s.insert(num);
    }
    
    return min(s.size(), nums.size() / 2);
}