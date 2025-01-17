#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    int size = numbers.size();
    vector<int> answer(size, -1);
    stack<int> st;

    for (int i = size - 1; i >= 0; --i) {
        
        while (!st.empty() && st.top() <= numbers[i]) {
            st.pop();
        }
        
        if (!st.empty()) {
            answer[i] = st.top();
        }
        
        st.push(numbers[i]);
    }

    return answer;

}