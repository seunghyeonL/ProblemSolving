#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(string t, string p) {
    int pSize = p.size();
    int tSize = t.size();
    long long intP = stoll(p);
    

    int result = 0;
    
    for (int i = 0 ; i < tSize - pSize + 1 ; i++) {
        string curSub = t.substr(i, pSize);
        long long intCurSub = stoll(curSub);

        if (intCurSub <= intP) {
            result++;
        }
    }
    return result;
}