#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    // 빈거 a개 주면 새거 b개 돌아옴, 처음 빈거 n개
    int result = 0;

    while (n >= a) {
        int numberToGet = (n / a) * b;
        result += numberToGet;
        n = numberToGet + n % a;
    }

    return result;
}