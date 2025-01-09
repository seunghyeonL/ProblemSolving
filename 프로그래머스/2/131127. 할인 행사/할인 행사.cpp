#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool checkDay(int n, unordered_map<string, int> &wn, vector<string> &want,
              vector<string> &discount)
{
    unordered_map<string, int> tmpwn;

    for (int i = n; i < n + 10; i++)
    {
        auto it = tmpwn.find(discount[i]);
        if (it == tmpwn.end())
        {
            tmpwn.insert({discount[i], 1});
        }
        else
        {
            tmpwn[discount[i]]++;
        }
    }

    // printp(tmpwn);

    for (string str : want)
    {
        if (wn[str] != tmpwn[str])
        {
            return false;
        }
    }

    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;

    unordered_map<string, int> wn;
    unordered_map<string, int> tmpwn;

    for (int i = 0; i < want.size(); i++)
    {
        wn.insert({want[i], number[i]});
    }

    // printp(wn);

    for (int i = 0; i < discount.size() - 10 + 1; i++)
    {
        if (checkDay(i, wn, want, discount))
        {
            answer++;
            // cout << answer << " ";
        }
        // cout << '\n';
    }

    return answer;
}