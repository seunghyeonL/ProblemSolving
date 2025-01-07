#include <string>
#include <vector>

using namespace std;

int move(int n, vector<int>& moveDp) {
    if (moveDp[n] != -1) {
        return moveDp[n];
    }
    
    if(n == 0) {
        moveDp[0] = 1;
        return moveDp[0];
    }
    
    if(n == -1) {
        return 0;
    }
    
    moveDp[n] = (move(n - 1, moveDp) + move(n - 2, moveDp)) % 1234567;
    return moveDp[n];
}

long long solution(int n) {
    vector<int> moveDp(2001, -1);
    
    return move(n, moveDp);
}