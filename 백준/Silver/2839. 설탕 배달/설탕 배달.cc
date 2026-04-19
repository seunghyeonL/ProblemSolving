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

    /*
     */
    int N;
    cin >> N;

    int answer = 0;
    while (N % 5 != 0)
    {
        if (N < 3)
        {
            answer = -1;
            break;
        }

        N -= 3;
        answer++;
    }

    if (answer != -1)
    {
        answer += N / 5;
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}