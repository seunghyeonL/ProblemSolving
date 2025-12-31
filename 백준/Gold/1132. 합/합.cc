#include <bits/stdc++.h>
using namespace std;

long long power10(int n)
{
    long long ret = 1;
    while (--n >= 0)
    {
        ret *= 10;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N;
    cin >> N;

    // 각 자릿수에 등장하는 알파벳 개수를 세고
    // 높은 자릿수에 많이 배치된 알파벳에 높은 숫자를 부여
    // 합 계산

    // A ~ J : 10개
    // W[i] : i알파벳 가중치
    // acc = sum i[0, 9] (W[i] * char_num[i])
    vector<long long> W(10);
    vector<int> char_num(10);

    // 제일 앞에 등장한 문자인가
    vector<bool> is_front(10);

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        int sz = str.size();
        is_front[str[0] - 'A'] = true;

        for (int i = 0; i < sz; i++)
        {
            char c = str[i];
            W[c - 'A'] += power10(sz - 1 - i);
        }
    }

    vector<int> chars(10);
    iota(chars.begin(), chars.end(), 0);

    // 가중치 순 내림차순
    sort(chars.begin(), chars.end(), [&W](int a, int b) { return W[a] > W[b]; });

    {
        // 0 부여할 문자가 가장 앞에 등장하지 않은 최소 가중치 문자가 되도록
        // 하면서 나머지 정렬 상태는 유지
        if (is_front[chars[9]])
        {
            int ci = 8;
            while (ci >= 0 && is_front[chars[ci]])
                ci--;

            vector<int> tmp = chars;
            copy(tmp.begin() + ci + 1, tmp.end(), chars.begin() + ci);
            chars.back() = tmp[ci];
        }
    }

    for (int i = 0; i < 10; i++)
        char_num[chars[i]] = 9 - i;

    long long ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += W[i] * char_num[i];
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
