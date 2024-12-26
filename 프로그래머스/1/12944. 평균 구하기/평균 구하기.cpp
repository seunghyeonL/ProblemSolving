#include <string>
#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>

using namespace std;

double solution(vector<int> arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0, plus<int>());
    int size = distance(arr.begin(), arr.end());
    return double(sum)/size;
    
}