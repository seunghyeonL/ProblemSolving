#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    for (char c : s)
    {
        if (!st.empty())
        {
            char t = st.top();
            
            if (t == '(' && c == ')') st.pop();
            else st.push(c);
        }
        else 
        {
            st.push(c);
        }
    }
    
    return st.empty() ? true : false;
}