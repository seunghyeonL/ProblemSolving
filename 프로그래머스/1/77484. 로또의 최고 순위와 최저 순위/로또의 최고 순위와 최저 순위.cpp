#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int resultNum = 0;
    
    for(int num : lottos) {
        auto it = find(win_nums.begin(), win_nums.end(), num);
        if(it != win_nums.end()) {
            resultNum++;
        }
    }
    
    int offset = accumulate(lottos.begin(), lottos.end(), 0, [](int acc, int cur) -> int {
        if (cur == 0) {
            return acc + 1;
        }
        return acc;
    });
        
    vector<int> mapper {6, 6, 5, 4, 3, 2, 1};
    
    answer.push_back(mapper[resultNum + offset]);
    answer.push_back(mapper[resultNum]);
    
    return answer;
}