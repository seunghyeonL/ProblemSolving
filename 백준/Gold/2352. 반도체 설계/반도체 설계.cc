#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> lis(n, 40001);

    int lislen = 0;

    for (int i = 0; i < n; i++)
    {
        int cur = v[i];
        int left = 0;
        int right = lislen;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (lis[mid] <= cur)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        lis[left] = cur;
        lislen = max(lislen, left + 1);
    }

    cout << lislen;

    // inputFileStream.close();
    return 0;
}