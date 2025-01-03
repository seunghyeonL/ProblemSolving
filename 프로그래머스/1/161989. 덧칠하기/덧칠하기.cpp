#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void paint(int startIdx, int n, int m, vector<bool> &isPainted) {
    for(int i = startIdx ; i < (n > startIdx + m ? startIdx + m : n); i++) {
        isPainted[i] = true;
    }
}

int solution(int n, int m, vector<int> section) {
    int result = 0;
    vector<bool> isPainted(n, true);

    for (auto el : section) {
        isPainted[el - 1] = false;
    }

    for (int i = 0; i < n; i++) {
        if (isPainted[i]) {
            continue;
        }

        paint(i, n,  m, isPainted);
        result++;
        // cout << "result: " << result << '\n';
        // printv(isPainted);
    }

    return result;
}