#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    string S, T;
    cin >> S >> T;

    // 문자열을 뒤에 추가하는 연산만 존재하므로
    // 역산방법도 한가지 뿐

    int N = S.size();

    while (T.size() > N)
    {
        if (T.back() == 'A')
            T.pop_back();
        else
        {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }

    cout << (S == T);

    // inputFileStream.close();
    return 0;
}