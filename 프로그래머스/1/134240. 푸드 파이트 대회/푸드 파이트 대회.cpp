#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    int size = food.size();
    string answer = "";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < food[i] / 2; j++) {
            answer += to_string(i);
        }
    }
    answer += '0';
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < food[i] / 2; j++) {
            answer += to_string(i);
        }
    }

    return answer;
}