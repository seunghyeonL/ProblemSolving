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
        i개의 로프 사용 -> 하중 : w / i
        최대 버틸 수 있는 무게 : w = min(로프 한계)) * i

        로프 한계가 큰 로프부터 하나씩 추가해가면 됨
    */

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    int res = 0;

    for (int i = 0; i < N; i++)
    {
        res = max(res, v[i] * (i + 1));
    }

    cout << res << '\n';
    // inputFileStream.close();
    return 0;
}