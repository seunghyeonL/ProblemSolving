#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int result = 0;
    for(int i = 2 ; i <= n ; i += 2) {
        result += i;
    }
    return result;
}