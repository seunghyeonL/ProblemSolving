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
        한 대각선에 하나만 배치하는 식으로 넘어가면서
        다른 대각선은 사용 여부 체크
    */

    string s;
    cin >> s;

    int N = s.size();
    vector<string> v;
    for (int i = 0; i < N; i++)
    {
        v.push_back(s.substr(i));
    }

    sort(v.begin(), v.end());

    for (string el : v)
    {
        cout << el << '\n';
    }

    // inputFileStream.close();
    return 0;
}
