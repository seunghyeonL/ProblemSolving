#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int result = 0;
    
    for(int i = left ; i <= right ; i++) {
        result += i;
    }
    
    int i = 0;
    while(i*i <= right) {
        if (i*i >= left) {
            result -= 2*i*i;
        }
        i++;
    }
    
    return result;
}