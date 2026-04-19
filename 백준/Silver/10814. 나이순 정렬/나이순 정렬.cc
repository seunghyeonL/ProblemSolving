#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N;
pair<int, string> arr[NMX];

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

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;

        arr[i] = {age, name};
    }

    stable_sort(arr, arr + N,
                [](const auto &a, const auto &b) { return a.first < b.first; });

    for (int i = 0; i < N; i++)
    {
        auto [age, name] = arr[i];

        cout << age << ' ' << name << '\n';
    }

    // inputFileStream.close();
    return 0;
}