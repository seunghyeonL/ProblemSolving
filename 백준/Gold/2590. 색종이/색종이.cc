#include <bits/stdc++.h>
using namespace std;    

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
    // 가능한 큰거부터 채우기

    vector<int> arr(7);
    for (int i = 1; i <= 6; i++)
        cin >> arr[i];

    int ans = 0;

    ans += arr[6];

    while (arr[5] > 0)
    {
        ans++;
        arr[5]--;
        if (arr[1] > 0)
            arr[1] = max(arr[1] - (36 - 25), 0);
    }

    while (arr[4] > 0)
    {
        ans++;
        arr[4]--;
        int n = 36 - 16;
        while (arr[2] > 0 && n >= 4)
        {
            arr[2]--;
            n -= 4;
        }

        if (arr[1] > 0)
            arr[1] = max(arr[1] - n, 0);
    }

    while (arr[3] > 0)
    {
        ans++;
        int n = 36;
        while (arr[3] > 0 && n >= 9)
        {
            arr[3]--;
            n -= 9;
        }

        if (n == 27)
        {
            for (int i = 0 ; i < 5 && arr[2] > 0; i++)
            {
                arr[2]--;
                n -= 4;
            }
        }
        else if (n == 18)
        {
            for (int i = 0 ; i < 3 && arr[2] > 0; i++)
            {
                arr[2]--;
                n -= 4;
            }
        }
        else if (n == 9)
        {
            if (arr[2] > 0)
            {
                arr[2]--;
                n -= 4;
            }
        }

        if (arr[1] > 0)
            arr[1] = max(arr[1] - n, 0);
    }

    while (arr[2] > 0)
    {
        ans++;
        int n = 36;
        while (arr[2] > 0 && n >= 4)
        {
            arr[2]--;
            n -= 4;
        }

        if (arr[1] > 0)
            arr[1] = max(arr[1] - n, 0);
    }

    while (arr[1] > 0)
    {
        ans++;
        arr[1] = max(arr[1] - 36, 0);
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}