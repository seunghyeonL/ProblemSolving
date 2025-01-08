#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements)
{
    int size = elements.size();
    set<int> s;
    vector<int> ps;

    ps.push_back(0);

    for (int i = 0; i < elements.size(); i++)
    {
        ps.push_back(ps.back() + elements[i]);
    }

    for (int i = 0; i < elements.size(); i++)
    {
        ps.push_back(ps.back() + elements[i]);
    }

    // printv(ps);

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < i + size + 1; j++)
        {
            // cout << ps[j] - ps[i] << endl;
            s.insert(ps[j] - ps[i]);
        }
    }

    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << '\n' << '\n';

    return s.size();
}
