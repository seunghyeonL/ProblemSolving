#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int N = cookie.size();
    
    auto solve = [&](int m)
    {
        int l = 0;
        int r = N - 1;
        int lsum = accumulate(cookie.begin(), cookie.begin() + m + 1, 0);
        int rsum = accumulate(cookie.begin() + m + 1, cookie.end(), 0);
        
        // cout << lsum << ' ' << rsum << '\n';
        
        while (true)
        {
            if (lsum > rsum && l == m) break;
            if (lsum < rsum && r == m + 1) break;
            
            while (lsum > rsum && l < m) lsum -= cookie[l++];
            while (lsum < rsum && r > m + 1) rsum -= cookie[r--];
            
            // cout << lsum << ' ' << rsum << '\n';
            
            if (lsum == rsum) 
            {
                answer = max(answer, lsum);
                break;
            }
        }
    };
    
    for (int i = 0 ; i < N - 1 ; i++)
    {
        solve(i);
    }
    
    return answer;
}