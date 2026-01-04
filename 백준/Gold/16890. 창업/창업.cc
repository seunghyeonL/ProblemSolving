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

    /*
        apple이 넣을 차례의 문자가
        cube 모든 문자보다 작으면 제일 뒤에 넣기

        반대도 마찬가지
    */

    deque<char> apple, cube;

    {
        string apple_str, cube_str;
        cin >> apple_str >> cube_str;

        apple.assign(apple_str.begin(), apple_str.end());
        cube.assign(cube_str.begin(), cube_str.end());
    }

    int N = apple.size();

    sort(apple.begin(), apple.end());
    sort(cube.begin(), cube.end(), greater<char>());

    apple.resize(N / 2 + N % 2);
    cube.resize(N / 2);

    string ans;
    ans.resize(N);

    for (int i = 0, l = 0, r = N - 1; i < N; i++)
    {
        if (i % 2 == 0) // apple turn
        {
            if (apple.front() < cube.front())
            {
                ans[l++] = apple.front();
                apple.pop_front();
            }
            else
            {
                ans[r--] = apple.back();
                apple.pop_back();
            }
        }
        else // cube turn
        {
            if (cube.front() > apple.front())
            {
                ans[l++] = cube.front();
                cube.pop_front();
            }
            else
            {
                ans[r--] = cube.back();
                cube.pop_back();
            }
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}