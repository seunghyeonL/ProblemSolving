#include <bits/stdc++.h>
using namespace std;
const int LMX = 500000;
int K, L;
unordered_map<string, int> waitingIdx; // 학번: waiting 배열에서의 idx
vector<string> waiting(LMX);

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> K >> L;

    for (int i = 0; i < L; i++)
    {
        string id;
        cin >> id;
        waitingIdx[id] = i;
    }

    for (auto [id, idx] : waitingIdx)
    {
        waiting[idx] = id;
    }

    waiting.erase(remove(waiting.begin(), waiting.end(), string()), waiting.end());

    for (int i = 0; i < min(K, int(waiting.size())); i++)
    {
        cout << waiting[i] << '\n';
    }

    // inputFileStream.close();
    return 0;
}