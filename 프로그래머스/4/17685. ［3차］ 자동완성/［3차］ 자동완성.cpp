#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> words)
{
    int answer = 0;
    int size = words.size();

    sort(words.begin(), words.end());

    auto getSameLen = [](const string &a, const string &b)
    {
        int sizeA = a.size();
        int sizeB = b.size();
        int result = min(sizeA, sizeB);

        for (int i = 0; i < min(sizeA, sizeB); i++)
        {
            if (a[i] != b[i])
            {
                result = i;
                break;
            }
        }

        return result;
    };

    // 사전순으로 정렬한 words에서 인접한 것 끼리 앞에서부터 최대로 겹치는 수를
    // 파악
    for (int i = 0; i < size; i++)
    {
        int len = words[i].size();
        int l1 = i > 0 ? getSameLen(words[i - 1], words[i]) : 0;
        int l2 = i < size - 1 ? getSameLen(words[i], words[i + 1]) : 0;

        answer += min(max(l1, l2) + 1, len);
    }

    return answer;
}