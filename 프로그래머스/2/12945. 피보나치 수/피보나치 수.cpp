#include <string>
#include <vector>

using namespace std;
vector<int> fiboDp{0, 1, 1};

int fibo(int n) {
    if (n < fiboDp.size()) {
        return fiboDp[n];
    }
    
    fiboDp.push_back((fibo(n - 1) + fibo(n - 2)) % 1234567);

    return fiboDp.back();
}

int solution(int n) {
    
    return fibo(n) % 1234567;
}