#include <bits/stdc++.h>
using namespace std;

struct Event
{
    int time;
    int type; // 0 : start, 1 : finish
};

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        0덩어리개수, 1덩어리 개수 중 작은것이 정답
     */

    int N;
    cin >> N;

    vector<Event> events;

    for (int i = 0; i < N; i++)
    {
        int start, finish;
        cin >> start >> finish;

        events.push_back({start, 0});
        events.push_back({finish, 1});
    }

    sort(events.begin(), events.end(), [](auto &a, auto &b)
         { return a.time == b.time ? a.type > b.type : a.time < b.time; });

    int mxClassCnt = 0;
    int classCnt = 0;

    for (auto [time, type] : events)
    {
        if (type == 0)
        {
            classCnt++;
            mxClassCnt = max(mxClassCnt, classCnt);
        }
        else
        {
            classCnt--;
        }
    }

    cout << mxClassCnt << '\n';

    // inputFileStream.close();
    return 0;
}