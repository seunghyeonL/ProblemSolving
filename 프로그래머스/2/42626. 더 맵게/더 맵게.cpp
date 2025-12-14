#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int ans = 0;
    bool ok = false;
    
    while (!pq.empty())
    {
        if (pq.top() >= K)
        {
            ok = true;
            break;
        }
        
        if (pq.size() == 1) 
            break;
        
        int s = pq.top();
        pq.pop();
        
        int b = pq.top();
        pq.pop();
        
        ans++;
        
        int m = s + 2 * b;
        pq.push(m);
    }
    
    return ok ? ans : -1;
}