#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int result = 0;

    for (int i = 0; i <= 9; i++) {
        auto it = find(numbers.begin(), numbers.end(), i);
        if (it == numbers.end()) {
            result += i;
        }
    }

    return result;
}