#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 1 ~ N 까지 수에서 min(총 소인수 2 갯수, 총 소인수 5 갯수)
    int N;
    cin >> N;

    int n2 = 0;
    int n5 = 0;
    for (int i = 1; i <= N; i++)
    {
        int n = i;
        while (n % 2 == 0)
        {
            n /= 2;
            n2++;
        }

        while (n % 5 == 0)
        {
            n /= 5;
            n5++;
        }
    }

    cout << min(n2, n5) << '\n';

    // ifstream inputFileStream("input.txt");

    // inputFileStream.close();
    return 0;
}