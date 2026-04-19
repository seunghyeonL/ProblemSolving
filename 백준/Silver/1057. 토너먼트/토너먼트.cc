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
        번호 n인 참가자의 다음라운드에서 자신의 번호:
        (n - 1) / 2 + 1

        i라운드에서 번호가 같아지는 사람은 i - 1라운드에서 맞붙는다.
    */

    // ifstream inputFileStream("input.txt");

    int N;
    cin >> N;

    int A, B;
    cin >> A >> B;

    int ans = -1;
    for (int i = 2;; i++)
    {
        A = (A - 1) / 2 + 1;
        B = (B - 1) / 2 + 1;

        if (A == B)
        {
            ans = i - 1;
            break;
        }
    }

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}