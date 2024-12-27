#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    auto minIt = min_element(arr.begin(), arr.end());

    vector<int> answer;

    int index = 0;
    copy_if(arr.begin(), arr.end(), back_inserter(answer),
            [&index, &minIt, &arr](auto el) -> auto {
                return arr.begin() + index++ != minIt;
            });

    if(answer.size() == 0) {
        answer.push_back(-1);
    }
    return answer;
}