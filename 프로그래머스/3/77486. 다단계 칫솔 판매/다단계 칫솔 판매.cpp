#include <string>
#include <vector>
#include <functional>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enrolls, vector<string> referrals, vector<string> sellers, vector<int> amounts)
{

    int size = enrolls.size();
    vector<int> answer(size, 0);

    unordered_map<string, int> enrollIdxMap;
    unordered_map<string, string> referralMap;

    for (int i = 0; i < size; i++)
    {
        enrollIdxMap[enrolls[i]] = i;
        referralMap[enrolls[i]] = referrals[i];
    }

    for (int &amount : amounts)
    {
        amount *= 100;
    }

    function<void(string, int)> distributeIncome = [&](string seller, int amount)
    {
        int distributedAmount = amount / 10;
        
        int selfAmount = amount - distributedAmount;
        answer[enrollIdxMap[seller]] += selfAmount;
        
        if (distributedAmount == 0)
            return;

        if (referralMap[seller] != "-")
        {
            distributeIncome(referralMap[seller], distributedAmount);
        }
    };

    for (int i = 0; i < sellers.size(); i++)
    {
        distributeIncome(sellers[i], amounts[i]);
    }

    return answer;
}