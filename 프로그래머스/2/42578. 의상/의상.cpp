#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    vector<int> resultDp{0};
    unordered_map<string, int> categoryum;

    for (auto cloth : clothes)
    {
        auto it = categoryum.find(cloth[1]);
        if (it == categoryum.end())
        {
            categoryum.insert({cloth[1], 1});
        }
        else
        {
            categoryum[cloth[1]]++;
        }
    }

    int idx = 1;
    for (auto [category, num] : categoryum)
    {
        resultDp.push_back((resultDp[idx++ - 1] + 1) * (num + 1) - 1);
    }

    return resultDp[categoryum.size()];
}
