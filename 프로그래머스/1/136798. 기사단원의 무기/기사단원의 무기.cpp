#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getDividerNumber(int n) {
    int result = 0;
    float rootN = sqrt(double(n));

    for (int i = 1; i <= sqrt(double(n)); i++) {
        if (n % i == 0) {
            result += 2;
            if (i == sqrt(double(n))) {
                result -= 1;
            }
        }
    }
    return result;
}

int solution(int number, int limit, int power) {
    int answer = 0;

    for (int i = 1; i <= number; i++) {
        int deviderNumber = getDividerNumber(i);
        answer += (deviderNumber > limit ? power : deviderNumber);
    }

    return answer;
}
