#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int N;
P arr[500001]; // 키, 자기보다 키큰사람 허용치
multiset<int> teams;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        키가 큰사람부터 팀에 배정해가면
        이미 배정된 사람은 새로운 사람이 들어와도 영향을 받지 않는다.
        또한 새로 배정되는 사람은 자신이 가장 작다.
        큰 사람부터 들어갈 수 있는 가장 사람이 많은 팀에 넣어주기 - 그리디
        팀들을 multiset<int>로 관리하여 새로 사람을 넣을때
        그 요소를 빼고 int값을 1 늘리고 다시 넣어주면 되겠다.
     */

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    sort(arr, arr + N, greater<P>());

    for (int i = 0; i < N; i++)
    {
        auto [h, k] = arr[i];

        auto it = teams.lower_bound(k);
        if (it == teams.begin())
        {
            teams.insert(1);
        }
        else
        {
            --it;
            int targetTeamSize = *it;
            teams.erase(it);
            teams.insert(targetTeamSize + 1);
        }
    }

    cout << teams.size() << '\n';

    // inputFileStream.close();
    return 0;
}
