#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> completionMap;
    
    for (string name : participant)
    {
        completionMap[name] = 0;
    }
    
    for (string name : completion)
    {
        completionMap[name]++;
    }
    
    for (string name : participant)
    {
        if (completionMap[name]-- == 0)
        {
            return name;
        }
    }
}