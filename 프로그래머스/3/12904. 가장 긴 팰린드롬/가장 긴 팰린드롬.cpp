#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer = 1;
    int size = s.size();
    for (int i = 1 ; i < size ; i++)
    {
        int halfLen = 1;

        // odd palindrome
        while (i - halfLen >= 0 && i + halfLen < size)
        {
            if (s[i - halfLen] == s[i + halfLen])
            {
                answer = max(answer, 1 + 2 * halfLen);
                halfLen++;
            }
            else
            {
                break;
            }
        }

        halfLen = 1;
        // even palindrome
        while (i - halfLen >= 0 && i + halfLen - 1 < size)
        {
            if (s[i - halfLen] == s[i + halfLen - 1])
            {
                answer = max(answer, 2 * halfLen);
                halfLen++;
            }
            else
            {
                break;
            }
        }
    }

    return answer;
}