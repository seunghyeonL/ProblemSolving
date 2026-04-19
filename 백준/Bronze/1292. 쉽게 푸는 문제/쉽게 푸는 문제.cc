#include <bits/stdc++.h>
using namespace std;

vector<int> num;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        n!에서 소수 p의 개수
        = sum n/p + n/p^2 + ...
    */

    // ifstream inputFileStream("input.txt");

    int A, B;
    cin >> A >> B;

    num.push_back(0);
    for (int i = 1; num.size() <= 1001; i++)
    {
        for (int j = 0; j < i; j++)
        {
            num.push_back(i);
        }
    }

    int ans = 0;
    for (int i = A; i <= B; i++)
    {
        ans += num[i];
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}