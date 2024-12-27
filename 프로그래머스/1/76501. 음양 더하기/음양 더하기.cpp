#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int result = 0;
    int size = absolutes.size();
    for (int i = 0; i < size; i++) {
        if (signs[i]) {
            result += absolutes[i];
        } else {
            result += -1 * absolutes[i];
        }
    }
    return result;
}