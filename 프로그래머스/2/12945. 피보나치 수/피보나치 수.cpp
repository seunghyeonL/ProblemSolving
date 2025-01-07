#include <string>
#include <vector>

using namespace std;


int fibo(int n, vector<int> &fiboDp) {
    if (n < fiboDp.size()) {
        return fiboDp[n];
    }
    
    fiboDp.push_back((fibo(n - 1, fiboDp) + fibo(n - 2, fiboDp)) % 1234567);

    return fiboDp.back();
}

int solution(int n) {
    vector<int> fiboDp{0, 1, 1};
    
    return fibo(n, fiboDp) % 1234567;
}