#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    multiset<int> s;
    vector<int> v;

    copy_if(arr.begin(), arr.end(), inserter(s, s.end()),
            [divisor](auto el) -> auto { return el % divisor == 0; });

    transform(s.begin(), s.end(), back_inserter(v),
              [](auto x) -> auto { return x; });
    
    if(v.size() == 0) {
        v.push_back(-1);
    }

    return v;
}
