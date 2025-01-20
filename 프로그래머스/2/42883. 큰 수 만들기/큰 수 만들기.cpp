#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer{};
    int size = number.size();

    int remainSize = size;
    int needSize = size - k;

    int idx = 0;
    while (idx < size)
    {

        int n = number[idx];

        // cout << "before remainSize: " << remainSize << " needSize: " <<
        // needSize
        //      << '\n';

        if (answer.empty())
        {
            // cout << "push!" << '\n';
            answer.push_back(n);
            --remainSize;
            --needSize;
            ++idx;
            continue;
        }

        while (remainSize > needSize)
        {
            if (!answer.empty() && answer.back() < n)
            {
                // cout << "pop!" << '\n';
                answer.pop_back();
                ++needSize;
                continue;
            }
            break;
        }

        if (needSize > 0)
        {
            // cout << "push!" << '\n';
            answer.push_back(n);
            --remainSize;
            --needSize;
            // cout << "after remainSize: " << remainSize
            //      << " needSize: " << needSize << '\n';
            
        }
        ++idx;
    }

    return answer;
}
