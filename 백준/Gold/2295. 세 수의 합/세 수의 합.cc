#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        두 개 합 set -> O(N^2)

        Ax + Ay + Az = Ak가 되는가?
        Ax + Ay = Ak - Az일 수 있는가? O(N^2logN)
    */

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    unordered_set<int> us;

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            us.insert(v[i] + v[j]);
        }
    }

    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (us.count(v[i] - v[j]))
            {
                cout << v[i];
                return 0;
            }
        }
    }

    // inputFileStream.close();
    return 0;
}
