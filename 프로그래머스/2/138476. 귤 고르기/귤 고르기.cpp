#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> arr) {
    unordered_map<int, int> um;
    vector<pair<int, int>> v;

    for (int el : arr) {
        auto it = um.find(el);
        if (it == um.end()) {
            um.insert({el, 1});
        } else {
            it->second++;
        }
    }

    for (auto it = um.begin(); it != um.end(); it++) {
        v.push_back({it->first, it->second});
    }

    sort(v.begin(), v.end(),
         [](auto a, auto b) -> bool { return a.second > b.second; });

    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i].first << " " << v[i].second << '\n';
    // }

    int cnt = 0;
    int result = 0;
    for (auto p : v) {
        cnt += p.second;
        result++;
        if (cnt >= k) {
            break;
        }
    }

    return result;
}
