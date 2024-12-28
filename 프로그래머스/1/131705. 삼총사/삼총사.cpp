#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int size = number.size();
    int result = 0;

    for (int i = 0 ; i < size - 2 ; i++) {
        for (int j = i + 1 ; j < size - 1 ; j++) {
            for (int k  = j + 1 ; k < size ; k++) {
                int sum = number.at(i) + number.at(j) + number.at(k);
                if (sum == 0) {
                    result++;
                }
            }
        }
    }

    return result;
}