#include <bits/stdc++.h>
using namespace std;

// 문자열 비교를 동일한 부분 뒤에 오는 문자가 작은 순으로 먼저 봐야함
// <=> s1 + s2 < s2 + s1

int N;
vector<string> arr;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    arr.resize(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    auto compare = [&](const string &a, const string &b)
    {
        // min_heap 으로 만들거니 내림차순으로
        return a + b > b + a;
    };

    priority_queue<string, vector<string>, decltype(compare)> pq(compare);

    for (auto &el : arr)
    {
        pq.push(el);
    }

    string ans{};

    while (!pq.empty())
    {
        string cs = pq.top();
        pq.pop();

        ans.push_back(cs[0]);

        if (cs.size() > 1)
            pq.push(cs.substr(1));
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
