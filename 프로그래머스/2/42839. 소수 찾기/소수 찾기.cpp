#include <string>
#include <vector>
#include <set>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    if (n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}


vector<string> permutation(string numbers, int cnt)
{
    vector<string> result;
    if (cnt == 1)
    {
        for (char number : numbers)
        {
            string cur{};
            cur.push_back(number);
            result.push_back(cur);
        }
    }

    int size = numbers.size();
    char pick{};

    for (int i = 0; i < size; i++)
    {
        pick = numbers[i];
        string notPicked = numbers.substr(0, i) + numbers.substr(i + 1);
        vector<string> notPickedCombs = permutation(notPicked, cnt - 1);

        for (string notPickedComb : notPickedCombs)
        {
            string curComb{};
            curComb += pick;
            curComb += notPickedComb;
            result.push_back(curComb);
        }
    }

    return result;
}

int solution(string numbers)
{
    int answer = 0;
    int size = numbers.size();
    set<int> s;

    for (int i = 1; i <= size; i++)
    {
        vector<string> v = permutation(numbers, i);

        for (string perm : v)
        {
            s.insert(stoi(perm));
        }
    }

    for (int perm : s)
    {
        // cout << perm << " ";
        if (isPrime(perm))
        {
            answer++;
        }
    }
    // cout << '\n';

    return answer;
}
