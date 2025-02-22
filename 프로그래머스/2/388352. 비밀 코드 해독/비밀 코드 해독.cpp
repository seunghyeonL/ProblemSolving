#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename Cont, typename PrintFunctor = void>
struct Prints
{
    PrintFunctor printEl;
    void operator()(Cont cont)
    {
        for (auto el : cont)
        {
            printEl(el);
        }
        cout << '\n';
    }
};

template <typename Cont>
struct Prints<Cont, void>
{
    void operator()(Cont cont)
    {
        for (auto el : cont)
        {
            cout << el << " ";
        }
        cout << '\n';
    }
};

int getDupleNum(const vector<int>& a, const vector<int>& b)
{
    set<int> s(a.begin(), a.end());
    for(int el : b)
    {
        s.insert(el);
    }
    
    return a.size() + b.size() - s.size();
}


int solution(int n, vector<vector<int>> q, vector<int> ans) 
{
    // Prints<vector<int>> prints;
    // Prints<vector<bool>> printb;
    int answer = 0;
    int m = q.size();
    
    vector<int> numbers(n);
    for(int i = 0 ; i < n ; i++) numbers[i] = i + 1;
    
    vector<bool> pick(n, false);
    for(int i = 0 ; i < 5 ; i++) pick[i] = true;
    
    
    do {
        // printb(pick);
        vector<int> curComb;
        for(int i = 0 ; i < n ; i++)
        {
            if(pick[i]) curComb.emplace_back(numbers[i]);
        }
        // prints(curComb);
        
        bool correctFlag = true;
        for(int i = 0 ; i < m ; i++)
        {            
            if(ans[i] != getDupleNum(curComb, q[i])) 
            {
                correctFlag = false;
                break;
            }
            // cout << "curComb: ";
            // prints(curComb);
            // cout << "q[i]: ";
            // prints(q[i]);
            // cout << "ans[i]: " << ans[i] << '\n';
            
        }
        if(correctFlag) answer++;
    } while(prev_permutation(pick.begin(), pick.end()));
    
    
    return answer;
}