#include <string>
#include <vector>

using namespace std;

int dfs(const vector<int> &numbers, int acc, int cnt, int target)
{
    if (cnt == numbers.size())
    {
        return acc == target ? 1 : 0;
    }

    return dfs(numbers, acc + numbers[cnt], cnt + 1, target) +
           dfs(numbers, acc - numbers[cnt], cnt + 1, target);
}

int solution(vector<int> numbers, int target)
{
    return dfs(numbers, 0, 0, target);
}