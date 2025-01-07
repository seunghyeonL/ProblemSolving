#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    return accumulate(arr.begin(), arr.end(), arr[0], lcm<int, int>);
}