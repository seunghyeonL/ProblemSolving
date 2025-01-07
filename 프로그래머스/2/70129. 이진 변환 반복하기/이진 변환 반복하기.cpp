#include <string>
#include <vector>

using namespace std;

void solve(string s, int &cnt, int &zeroCnt) {
    string result{};
    string tmp{};

    // cout << s << " " << cnt << " " << zeroCnt << '\n';

    for (char chr : s) {
        if (chr == '1') {
            tmp += chr;
        } else {
            zeroCnt++;
        }
    }

    int n = tmp.size();

    while (n > 0) {
        result += to_string(n % 2);
        n /= 2;
    }

    if (s == "1") {
        return;
    }

    cnt++;
    solve(result, cnt, zeroCnt);
}

vector<int> solution(string s) {
    vector<int> answer;

    int cnt = 0;
    int zeroCnt = 0;

    solve(s, cnt, zeroCnt);

    answer.push_back(cnt);
    answer.push_back(zeroCnt);

    return answer;
}