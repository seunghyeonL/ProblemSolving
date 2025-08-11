#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(std::vector<int> a)
{
    int answer = 0;
    int size = a.size();

    unordered_map<int, vector<int>> um; // 숫자, idx들

    for (int i = 0; i < size; i++)
    {
        um[a[i]].push_back(i);
    }

    for (int i = 0; i < size; i++)
    {
        int len = 0;
        vector<int> idxs = um[i];
        vector<bool> used(size);

        for (int idx : idxs)
        {
            used[idx] = true;
        }

        for (int idx : idxs)
        {
            if (idx > 0 && !used[idx - 1])
            {
                used[idx - 1] = true;
                len += 2;
            }
            else if (idx < size - 1 && !used[idx + 1])
            {
                used[idx + 1] = true;
                len += 2;
            }
        }

        answer = max(answer, len);
    }

    return answer;
}
