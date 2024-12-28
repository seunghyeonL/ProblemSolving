#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int runCommand(vector<int> &array, vector<int> &command) {
    vector<int> result;
    int i = command.at(0);
    int j = command.at(1);
    int k = command.at(2);
    
    for(int idx = i - 1 ; idx <= j - 1 ; idx++) {
        result.push_back(array.at(idx));
    }
    
    sort(result.begin(), result.end());
    
    return result.at(k - 1);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto command : commands) {
        answer.push_back(runCommand(array, command));
    }
    
    return answer;
}