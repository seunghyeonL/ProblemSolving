#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        자릿수별로 묶어서 처리하기
     */

    // ifstream inputFileStream("input.txt");

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        arr.push_back(n);
    }

    int f = arr[0];

    for (int i = 1; i < N; i++)
    {
        int g = gcd(f, arr[i]);
        cout << f / g << '/' << arr[i] / g << '\n';
    }

    // inputFileStream.close();
    return 0;
}