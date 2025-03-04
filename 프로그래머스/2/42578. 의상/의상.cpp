#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    vector<int> resultDp{0};
    unordered_map<string, int> categoryNum;

    for (auto cloth : clothes)
    {
        // auto it = categoryNum.find(cloth[1]);
        // if (it == categoryNum.end())
        // {
        //     categoryNum.insert({cloth[1], 1});
        // }
        // else
        // {
        //     categoryNum[cloth[1]]++;
        // }
        categoryNum[cloth[1]]++;
    }

    int idx = 1;
    for (auto [category, num] : categoryNum)
    {
        resultDp.push_back((resultDp[idx++ - 1] + 1) * (num + 1) - 1);
    }

    return resultDp[categoryNum.size()];
}
