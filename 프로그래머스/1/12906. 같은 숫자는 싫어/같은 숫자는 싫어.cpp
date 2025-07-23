#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for (int el : arr)
    {
        if (!answer.empty() && *prev(answer.end()) == el)
        {
            continue;
        }
        
        answer.push_back(el);
    }

    return answer;
}