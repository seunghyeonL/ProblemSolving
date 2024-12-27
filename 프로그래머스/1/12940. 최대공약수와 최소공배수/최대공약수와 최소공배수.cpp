#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, int m) {
    int a = max(n, m);
    int b = min(n, m);

    int gcd = 0;
    int r = 0;
    while (true) {
        r = a % b;

        if (r == 0) {
            gcd = b;
            break;
        }

        a = b;
        b = r;
    }

    int lcm = m * n / gcd;

    vector<int> result{gcd, lcm};
    return result;
}
