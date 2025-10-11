#include <bits/stdc++.h>
using namespace std;

const int EMX = 15;
const int SMX = 28;
const int MMX = 19;
const int LMT = lcm(lcm(EMX, SMX), MMX);

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        (n - 1) % EMX = E - 1
        (n - 1) % SMX = S - 1
        (n - 1) % MMX = M - 1
     */

    int E, S, M;
    cin >> E >> S >> M;

    E -= 1;
    S -= 1;
    M -= 1;

    int answer{};
    for (int n = 0; n < LMT; n++)
    {
        if (n % EMX == E && n % SMX == S && n % MMX == M)
        {
            answer = n + 1;
            break;
        }
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}