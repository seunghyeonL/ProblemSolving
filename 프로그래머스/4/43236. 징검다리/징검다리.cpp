#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    int size = rocks.size();
    
    int left = 1;
    int right = distance;
    
    while (left <= right)
    {
        // 지점 사이 최솟값 중 최댓값
        int mid = (left + right) / 2;
        
        int removed = 0;
        int prev = 0;
        
        for (int i = 0 ; i < rocks.size() ; i++)
        {
            if (rocks[i] - prev < mid) 
            {
                removed++;
            }
            else
            {
                prev = rocks[i];
            }
        }
        
        if (distance - prev < mid)
        {
            removed++;
        }
        
        if (removed <= n)
        {
            left = mid + 1;
            answer = mid;
        }
        else
        {
            right = mid - 1;
        }
        
    }
    
    return answer;
}