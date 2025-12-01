#include <bits/stdc++.h>
using namespace std;

const int NMX = 10000;
int N;
int arr[NMX + 1];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        여려군데 동시구매가 가능하면 우선적으로 구매
        모든 수량이 완료되도록 while 반복


        a < b && b > c 인 a b c의 경우에는 2개부터 우선적으로 처리
    */

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    long long ans = 0;

    for (int i = 1; i <= N; i++)
    {
        while (arr[i] > 0)
        {
            if (i + 2 <= N && arr[i] > 0 && arr[i + 1] > 0 &&
                arr[i + 1] <= arr[i + 2])
            {
                ans += 7;
                arr[i]--;
                arr[i + 1]--;
                arr[i + 2]--;
            }
            else if (i + 1 <= N && arr[i] > 0 && arr[i + 1] > 0)
            {
                ans += 5;
                arr[i]--;
                arr[i + 1]--;
            }
            else
            {
                ans += 3;
                arr[i]--;
            }
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}