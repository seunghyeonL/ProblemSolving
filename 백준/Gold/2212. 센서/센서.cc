#include <bits/stdc++.h>
using namespace std;    

// 인접한 점 사이 거리 중
// 큰 순서로 K - 1개를 골라서
// 양 끝점 사이 거리에서 뺴기

const int NMX = 10000;
int N, K;
vector<int> arr;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> K;
    arr.resize(N);
    
    if (K >= N) 
    {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int mx = *max_element(arr.begin(), arr.end());
    int mn = *min_element(arr.begin(), arr.end());

    int L = mx - mn;

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> dist;
    for (int i = 0; i < (int)arr.size() - 1; i++)
        dist.push_back(arr[i + 1] - arr[i]);

    sort(dist.begin(), dist.end(), greater<int>());

    int sum = accumulate(dist.begin(), dist.begin() + K - 1, 0);

    cout << L - sum;

    // inputFileStream.close();
    return 0;
}