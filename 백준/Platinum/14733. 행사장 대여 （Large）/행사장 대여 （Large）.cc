#include <bits/stdc++.h>
using namespace std;

// y 좌표압축 해두고
// 각 yi 에 대해 직사각형 시작, 끝 이벤트로 x방향 스위핑
// 그러면서 현재 셀 너비를 채워나가기
const int NMX = 3000;
int N;

vector<tuple<int, bool, int, int>> events; // x, is_end, y1, y2,
// tuple<int, int, int, int> pos[NMX]; // 직사각형 모서리 두개

vector<int> comp_y;
unordered_map<int, int> idx_y;

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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        events.emplace_back(x1, 0, y1, y2);
        events.emplace_back(x2, 1, y1, y2);

        comp_y.push_back(y1);
        comp_y.push_back(y2);
    }

    sort(events.begin(), events.end());

    sort(comp_y.begin(), comp_y.end());
    comp_y.erase(unique(comp_y.begin(), comp_y.end()), comp_y.end());

    int sz_y = comp_y.size();

    for (int i = 0; i < sz_y; i++)
    {
        int y = comp_y[i];
        idx_y[y] = i;
    }

    long long ans = 0;

    for (int yi = 0; yi < sz_y - 1; yi++)
    {
        int y = comp_y[yi];
        int len_y = comp_y[yi + 1] - comp_y[yi]; // 현재 셀 y축 길이

        // 겹쳐진 직사각형 개수
        int cnt = 0;
        int px{};
        for (const auto &[x, is_end, y1, y2] : events)
        {
            // cell로 볼거라서 y2는 포함 x
            if (y < y1 || y >= y2)
                continue;

            // 시작점
            if (!is_end)
            {
                if (cnt++ == 0)
                    px = x;
            }
            else
            {
                if (--cnt == 0)
                    ans += (x - px) * len_y;
            }
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
