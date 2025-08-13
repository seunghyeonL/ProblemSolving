#include <string>
#include <vector>

using namespace std;

/*

    1 ->
    (1, 1)
    
    2 ->
    (1, 2)
    (2, 1)
    
    4 ->
    (1, 4)
    (2, 2)
    (4, 1)
    
    8 ->
    (1, 8)
    (2, 4)
    (4, 2)
    (8, 1)
*/

vector<int> solution(int e, vector<int> starts)
{
    int size = starts.size();
    vector<int> answer(size, 0);

    vector<int> memo(e + 1, 0); // memo[idx] : idx의 약수 개수

    for (int i = 1; i <= e; i++)
    {
        for (int j = i; j <= e; j += i)
        {
            memo[j]++;
        }
    }

    vector<int> best(e + 1, 0);
    best[e] = e;
    for (int i = e - 1; i >= 1; i--)
    {
        best[i] = (memo[i] >= memo[best[i + 1]] ? i : best[i + 1]);
    }

    for (int i = 0; i < size; i++)
    {
        int s = starts[i];
        answer[i] = best[s];
    }

    return answer;
}
