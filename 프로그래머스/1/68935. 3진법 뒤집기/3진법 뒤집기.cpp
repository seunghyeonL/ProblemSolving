#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    vector<int> nBase3;
    while (n > 0) {
        nBase3.push_back(n % 3);
        n /= 3;
    }

    reverse(nBase3.begin(), nBase3.end());

    int result = 0;
    for (int i = 0; i < nBase3.size(); i++) {
        int digitVal = nBase3.at(i);
        for (int j = 0 ; j < i ; j++) {
            digitVal *= 3;
        }
        result += digitVal;
    }

    return result;
}