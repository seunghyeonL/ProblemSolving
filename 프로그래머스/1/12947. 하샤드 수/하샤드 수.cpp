#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    int copyX = x;
    while (copyX > 0) {
        sum += copyX % 10;
        copyX /= 10; 
    }
    return x % sum == 0;
}