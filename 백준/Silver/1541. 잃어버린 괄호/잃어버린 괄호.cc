#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        처음 -가 나온 이후의 숫자는 다 빼주기
    */

    string s;
    cin >> s;

    vector<int> v;

    int answer = 0;
    int sign = 1;
    string n{};
    for (char c : s)
    {
        if (c >= '0' && c <= '9')
        {
            n.push_back(c);
        }
        else
        {
            answer += sign * stoi(n);
            n.clear();
            if (c == '-' || sign == -1)
                sign = -1;
        }
    }

    answer += sign * stoi(n);

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}