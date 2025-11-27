#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000000;
int N;
vector<long long> arr;

void reset()
{
    arr.clear();
}

void solve()
{
    cin >> N;
    long long sum = 0;

    reset();

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        sum += n;

        // 연속된 a, b, c가 a <= b && b >= c 인 경우를 압축
        // => 두 사람의 점수차는 동일
        /*
            4 3 10 10 10 7
            X, S - X

            diff == X - (sum - X)
            diff == -sum + 2 * X;
            2 * X == sum + diff;
            X = (sum + diff) / 2;
        */
        arr.push_back(n);

        while (arr.size() >= 3)
        {
            int sz = arr.size();
            long long a = arr[sz - 3];
            long long b = arr[sz - 2];
            long long c = arr[sz - 1];

            if (a <= b && b >= c)
            {
                arr.pop_back();
                arr.pop_back();
                arr.pop_back();
                arr.push_back((long long)((__int128)a - b + c));
            }
            else
                break;
        }
    }

    int sz = arr.size();
    long long diff = 0;

    int l = 0, r = sz - 1, turn = 0; // turn == 0 : 근우

    while (l <= r)
    {
        if (arr[l] < arr[r])
        {
            if (turn == 0)
                diff += arr[r--];
            else
                diff -= arr[r--];
        }
        else
        {
            if (turn == 0)
                diff += arr[l++];
            else
                diff -= arr[l++];
        }

        turn = (turn + 1) % 2;
    }

    cout << (sum + diff) / 2 << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int T;
    cin >> T;

    while (T-- > 0)
        solve();

    // inputFileStream.close();
    return 0;
}