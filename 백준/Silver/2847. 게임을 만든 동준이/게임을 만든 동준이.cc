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

    /*
        바로 뒤 수보다 같거나 크다면 바로 뒤 수보다 1 작게 만들기
     */

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int cnt = 0;
    for (int i = N - 2; i >= 0; i--)
        while (v[i] >= v[i + 1])
        {
            v[i]--;
            cnt++;
        }

    cout << cnt << '\n';
    // inputFileStream.close();
    return 0;
}
