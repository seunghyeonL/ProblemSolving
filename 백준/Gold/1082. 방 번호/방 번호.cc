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

    // 0이 아닌 수가 가능하면 하나는 있어야함
    // 수가 많아야함
    // 수가 같으면 큰 수가 많아야함

    int N, M;
    cin >> N;

    vector<int> P(N);   // P[n] : 숫자 n 가격
    vector<int> arr(N); // 숫자들 모음(내림차순 정렬할 것)

    for (int n = 0; n < N; n++)
    {
        int p;
        cin >> p;
        P[n] = p;
    }

    cin >> M;

    iota(arr.begin(), arr.end(), 0);
    // 가격순 오름차순, 번호순 내림차순
    sort(arr.begin(), arr.end(),
         [&P](int a, int b) { return P[a] == P[b] ? a > b : P[a] < P[b]; });

    // 동일 가격은 가장 높은 번호만 남기기
    arr.erase(unique(arr.begin(), arr.end(),
                     [&P](int a, int b) { return P[a] == P[b]; }),
              arr.end());

    int sz = arr.size();

    // M으로 가격이 가장 낮은카드를 우선으로 최대한 많이 구매
    // 단 0이 아닌 카드가 하나는 있어야함

    string ans{};
    // 맨 처음 카드는 0이 아닌 가장 작은 가격
    if (arr[0] == 0)
    {
        if (sz == 1 || M < P[arr[1]])
        {
            cout << 0 << '\n';
            return 0;
        }

        ans.push_back('0' + arr[1]);
        M -= P[arr[1]];
    }
    else
    {
        ans.push_back('0' + arr[0]);
        M -= P[arr[0]];
    }

    // 가장 작은 가격 최대한 많이 사기
    while (M >= P[arr[0]])
    {
        M -= P[arr[0]];
        ans.push_back('0' + arr[0]);
    }

    // 앞에서부터 남은 돈으로 최대한 크게 만들기
    for (int i = 0; i < ans.size(); i++)
    {
        int n = ans[i] - '0';

        for (int j = N - 1; j > n; j--)
        {
            if (P[j] <= P[n] + M)
            {
                ans[i] = '0' + j;
                M = M + P[n] - P[j];
                break;
            }
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
