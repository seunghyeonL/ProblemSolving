#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> cnt(50001);

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        cnt[n]++;
    }

    cout << *max_element(cnt.begin(), cnt.end());

    // inputFileStream.close();
    return 0;
}