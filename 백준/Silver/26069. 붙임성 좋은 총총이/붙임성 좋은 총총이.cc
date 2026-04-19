#include <bits/stdc++.h>
using namespace std;

unordered_set<string> us;
int N;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;

    us.insert("ChongChong");

    for (int i = 0; i < N; i++)
    {
        string a, b;
        cin >> a >> b;

        if (us.count(a) || us.count(b))
        {
            us.insert(a);
            us.insert(b);
        }
    }

    cout << us.size();

    // inputFileStream.close();
    return 0;
}