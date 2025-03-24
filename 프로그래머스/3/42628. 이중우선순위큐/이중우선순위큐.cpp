#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void operate(const string &operation, multiset<int> &s)
{
    char operationType = operation[0];
    int value = stoi(string(operation.begin() + 2, operation.end()));

    switch (operationType)
    {
    case 'I':
        s.insert(value);
        break;
    case 'D':
        if (s.empty())
            break;
        else if (value == 1)
            s.erase(prev(s.end()));
        else if (value == -1)
            s.erase(s.begin());
        break;
    }
}

vector<int> solution(vector<string> operations)
{
    vector<int> answer{0, 0};

    multiset<int> s;
    for (auto operation : operations)
    {
        operate(operation, s);
    }

    if (s.empty())
        return answer;
    else
    {
        answer[0] = *(prev(s.end()));
        answer[1] = *s.begin();
    }

    return answer;
}
