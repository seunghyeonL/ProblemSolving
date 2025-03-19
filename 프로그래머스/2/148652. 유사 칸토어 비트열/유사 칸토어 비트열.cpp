#include <string>
#include <vector>
#include <iostream>

using namespace std;

string generate(int n)
{
    if(n == 0) return "1";
    string prev = generate(n-1);
    string cur{};
    for(char el : prev)
    {
        if(el == '1') cur += "11011";
        else cur += "00000";
    }
    return cur;
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    string kt = generate(n);
    // cout << kt << '\n';
    
    for(long long i = l - 1 ; i <= r - 1 ; ++i)
    {
        // cout <<  i << ' ' << kt[i] << '\n';

        if(kt[i] == '1') 
        {
            ++answer;
        }
    }
    
    return answer;
}