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

    int N;
    while (cin >> N)
    {
        if (N == -1)
            break;

        vector<int> history;
        int sum = 0;
        for (int i = 1; i < N; i++)
        {
            if (N % i == 0)
            {
                history.push_back(i);
                sum += i;
            }
        }

        if (sum == N)
        {
            cout << N << " = ";
            for (int h : history)
            {
                cout << h;
                if (h != history.back())
                    cout << " + ";
            }
        }
        else
        {
            cout << N << " is NOT perfect.";
        }

        cout << '\n';
    }

    // inputFileStream.close();
    return 0;
}