#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string word)
{
    int answer = 0;
    vector<int> weights{1};
    for (int i = 1; i < 5; i++)
    {
        int back = weights.back();
        weights.push_back(back * 5 + 1);
    }

    unordered_map<char, int> um;
    um.insert({'A', 0});
    um.insert({'E', 1});
    um.insert({'I', 2});
    um.insert({'O', 3});
    um.insert({'U', 4});

    for (int i = 0; i < word.size(); i++)
    {
        auto weightsRIt = weights.rbegin();
        answer += *(weightsRIt + i) * um[word[i]];
        answer += 1;
    }

    return answer;
}
