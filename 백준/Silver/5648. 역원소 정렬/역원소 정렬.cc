#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[1000001];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        while (s.back() == '0')
        {
            s.pop_back();
        }

        reverse(s.begin(), s.end());

        arr[i] = stoll(s);
    }

    sort(arr, arr + N);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << '\n';
    }

    // inputFileStream.close();
    return 0;
}
