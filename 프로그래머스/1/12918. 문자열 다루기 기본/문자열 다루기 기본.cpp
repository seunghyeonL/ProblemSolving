#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    for (auto it = s.begin(); it < s.end(); it++) {
        if (!isdigit(*it)) {
            return false;
        }
    }
    
    int size = s.size();
    if (size != 6 && size != 4) {
        return false;
    }
    
    return true;
}
