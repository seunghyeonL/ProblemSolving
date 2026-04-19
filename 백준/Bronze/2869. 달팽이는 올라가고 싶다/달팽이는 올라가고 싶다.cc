#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, V;
    cin >> A >> B >> V;

    int t = 0;

    t += (V - A) / (A - B);
    V -= (A - B) * t;

    int h = 0;
    while (true)
    {
        t++;
        h += A;
        if (h >= V)
            break;
        h -= B;
    }

    cout << t << '\n';

    // ifstream inputFileStream("input.txt");

    // inputFileStream.close();
    return 0;
}