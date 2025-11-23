#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;
vector<int> comp;

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
        arr.push_back(n);
        comp.push_back(n);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int el : arr)
    {
        cout << (lower_bound(comp.begin(), comp.end(), el) - comp.begin())
             << ' ';
    }

    // inputFileStream.close();
    return 0;
}