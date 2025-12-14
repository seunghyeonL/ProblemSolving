#include <bits/stdc++.h>
using namespace std;

// A1 + ... + An == c 일때
// A1^2 + ... + An^2 최소가 되는 A1, ... , An찾기
// 그리디
// A1, ..., An이 최대한 똑같도록 평탄하게 

long long solution(int n, vector<int> works) {
    long long ans = 0;
    
    int sz = works.size();
    
    priority_queue<int> pq(works.begin(), works.end());
    
    for (int i = 0 ; i < n ; i++)
    {
        int mx = pq.top();
        pq.pop();
        
        if (mx == 0) 
            return 0;
        
        pq.push(mx - 1);
    }
    
    while (!pq.empty())
    {
        long long cur = pq.top();
        pq.pop();
        
        ans += cur * cur;
    }
    
    return ans;
}