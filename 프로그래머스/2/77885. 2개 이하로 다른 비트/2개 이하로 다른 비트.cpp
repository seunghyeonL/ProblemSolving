#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    0인 최하위 비트를 1로 바꾸고
    
    그 위치가 최하위 비트면 종료
    아니면 한칸 하위 비트를 0으로
*/

vector<long long> solution(vector<long long> numbers) {
    vector<long long> ans;
    
    for (ll n : numbers)
    {   
        int p = 0;
        while (true)
        {
            if (!(n >> p & 1)) // p 비트가 0이면
            {
                n ^= 1LL << p;
                
                if (p > 0)
                    n ^= 1LL << (p - 1);
                
                break;
            }
            
            p++;
        }
        
        ans.push_back(n);
    }
    
    return ans;
}