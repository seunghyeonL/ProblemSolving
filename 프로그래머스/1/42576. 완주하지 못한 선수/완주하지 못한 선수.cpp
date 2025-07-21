#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int size = completion.size();
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0 ; i < size ; i++)
    {
        if (participant[i] != completion[i])
        {
            return participant[i];
        }
    }
    
    return participant[size];
}