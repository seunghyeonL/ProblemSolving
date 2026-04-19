#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        감소하는 수는 모든 자리의 숫자가 다르다
        숫자 조합당 감소하는 수는 하나로 결정
        총 개수는 2^10
    */

    // ifstream inputFileStream("input.txt");

    int N;
    cin >> N;

    vector<int> v{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<long long> num;

    for (int bm = 1; bm < (1 << 10); bm++)
    {
        long long n = 0;
        for (int i = 0; i < 10; i++)
        {
            if (bm >> i & 1)
            {
                n *= 10;
                n += v[i];
            }
        }

        num.push_back(n);
    }

    sort(num.begin(), num.end());

    // for (long long n : num)
    //     cout << n << '\n';

    cout << (N >= num.size() ? -1 : num[N]) << '\n';

    // inputFileStream.close();
    return 0;
}