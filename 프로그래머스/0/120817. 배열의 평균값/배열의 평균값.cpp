#include <string>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> numbers) {
    int sum = accumulate(numbers.begin(), numbers.end(), 0, 
                      [](int a, int b) -> int {return a+b;});
    int size = distance(numbers.begin(), numbers.end());
    return double(sum)/size;
}