#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int size = scoville.size();
        
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int cnt = 0;
    while (pq.size() > 1)
    {
        int min1 = pq.top();
        if (min1 >= K) return cnt;
        
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        
        pq.push(min1 + min2 * 2);
        cnt++;
    }
    
    if (pq.top() >= K) return cnt;
    
    return -1;
}