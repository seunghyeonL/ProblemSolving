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

    string str;
    cin >> str;

    deque<char> dq;
    char mn = 'Z' + 1;
    for (char c : str)
    {
        if (c <= mn)
        {
            dq.push_front(c);
            mn = c;
        }
        else
            dq.push_back(c);
    }

    for (char c : dq)
        cout << c;

    // inputFileStream.close();
    return 0;
}