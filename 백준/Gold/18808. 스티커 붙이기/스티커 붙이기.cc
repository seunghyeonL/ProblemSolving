#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        스티커를 순서대로 붙인다.
        왼쪽 상단부터 붙인다.
        못붙이면 오른쪽으로 90도씩 돌려가며 붙인다.
        그래도 없으면 버림

        최종 스티커가 덮은 칸 개수 찾기
        
        각 스티커를 90도씩 회전한 상태를 미리 만들어두고 사용하기
    */

    using P = pair<int, int>; // x, y

    int N, M, K; // 세로 가로 스티커 개수
    cin >> N >> M >> K;

    vector<vector<bool>> notebook(N, vector<bool>(M));

    // stickers[i][j] : i번째 스티커 정보; j번 90도 회전한 스티커 정보
    vector<vector<vector<vector<bool>>>> stickers(K, vector<vector<vector<bool>>>(4));

    for (int k = 0; k < K; k++)
    {
        int R, C;
        cin >> R >> C;

        vector<vector<bool>> sticker(R, vector<bool>(C));

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                bool b;
                cin >> b;
                sticker[i][j] = b;
            }
        }

        stickers[k][0] = sticker;
    }

    for (int k = 0; k < K; k++)
    {
        for (int r = 1; r < 4; r++)
        {
            const vector<vector<bool>> &prevRotate = stickers[k][r - 1];

            int R = prevRotate.size();
            int C = prevRotate[0].size();

            vector<vector<bool>> rsticker(C, vector<bool>(R));

            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    rsticker[j][R - 1 - i] = prevRotate[i][j];
                }
            }

            stickers[k][r] = rsticker;
        }
    }

    auto stick = [&](int x0, int y0, const vector<vector<bool>> &sticker) -> bool
    {
        int R = sticker.size();
        int C = sticker[0].size();

        for (int i = x0; i < x0 + R; i++)
        {
            for (int j = y0; j < y0 + C; j++)
            {
                if (sticker[i - x0][j - y0] && notebook[i][j])
                    return false;
            }
        }

        for (int i = x0; i < x0 + R; i++)
        {
            for (int j = y0; j < y0 + C; j++)
            {
                notebook[i][j] = notebook[i][j] || sticker[i - x0][j - y0];
            }
        }

        return true;
    };

    auto setSticker = [&](int idx)
    {
        for (int r = 0; r < 4; r++)
        {
            const vector<vector<bool>> &sticker = stickers[idx][r];

            int R = sticker.size();
            int C = sticker[0].size();

            for (int i = 0; i < N - R + 1; i++)
            {
                for (int j = 0; j < M - C + 1; j++)
                {
                    if (stick(i, j, sticker))
                        return;
                }
            }
        }
    };

    for (int k = 0; k < K; k++)
    {
        setSticker(k);
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (notebook[i][j])
                res++;
        }
    }

    cout << res << '\n';

    // for (int k = 0; k < K; k++)
    // {
    //     for (int r = 0; r < 4; r++)
    //     {
    //         int R = stickers[k][r].size();
    //         int C = stickers[k][r][0].size();

    //         cout << k << "번째 스티커, " << r << "번 회전\n";
    //         for (int i = 0; i < R; i++)
    //         {
    //             for (int j = 0; j < C; j++)
    //             {
    //                 cout << stickers[k][r][i][j] << ' ';
    //             }
    //             cout << '\n';
    //         }
    //         cout << '\n';
    //     }
    // }

    // inputFileStream.close();
    return 0;
}