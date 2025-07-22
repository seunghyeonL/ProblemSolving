#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    
    // 시간, 가격
    stack<pair<int, int>> st;
    
    for (int t = 0 ; t < size ; t++)
    {
        if (st.empty()) 
        {
            st.push({t, prices[t]});
            continue;
        }
        
        while (!st.empty())
        {
            auto [time, price] = st.top();
            if (price > prices[t])
            {
                answer[time] = t - time;
                st.pop();
            }
            else break;
        }
        
        st.push({t, prices[t]});
    }
    
    while (!st.empty())
    {
        auto [time, price] = st.top();
        answer[time] = size - 1 - time;
        st.pop();
    }
    
    return answer;
}