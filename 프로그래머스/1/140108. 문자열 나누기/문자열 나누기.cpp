#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer{};
    
    int xN{};
    char curChr{};
    int otherN{};
    
    for(char chr : s) {
        if(xN == 0) {
            curChr = chr;
            xN++;
        } else if(curChr == chr) {
            xN++;
        } else {
            otherN++;
        }
        
        if(xN == otherN) {
            answer++;
            xN = 0;
            otherN = 0;
            curChr = char();
        }
    }
    
    if (xN > 0) {
        answer++;
    }
    
    return answer;
}