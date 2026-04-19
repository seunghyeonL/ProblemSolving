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
        이진 트리 순회
        벡터로 이진트리 만들기
        완전이진트리가 아니라서 세개 써야함; 아니면 2차원 배열이나 요소를 튜플로 하던지
    */

    int N;
    cin >> N;

    auto c2i = [](char c) -> int
    {
        return c == '.' ? -1 : c - 'A';
    };

    auto i2c = [](int n) -> char
    {
        return n == -1 ? '.' : 'A' + n;
    };

    vector<int> LC(N, -1);
    vector<int> RC(N, -1);

    for (int i = 0; i < N; i++)
    {
        char v, lc, rc;
        cin >> v >> lc >> rc;

        int vn = c2i(v);
        int lcn = c2i(lc);
        int rcn = c2i(rc);

        LC[vn] = lcn;
        RC[vn] = rcn;
    }

    function<void(int)> preOrder = [&](int cv)
    {
        cout << i2c(cv);
        if (LC[cv] >= 0)
            preOrder(LC[cv]);
        if (RC[cv] >= 0)
            preOrder(RC[cv]);
    };

    function<void(int)> inOrder = [&](int cv)
    {
        if (LC[cv] >= 0)
            inOrder(LC[cv]);
        cout << i2c(cv);
        if (RC[cv] >= 0)
            inOrder(RC[cv]);
    };

    function<void(int)> postOrder = [&](int cv)
    {
        if (LC[cv] >= 0)
            postOrder(LC[cv]);
        if (RC[cv] >= 0)
            postOrder(RC[cv]);
        cout << i2c(cv);
    };

    preOrder(0);
    cout << '\n';
    inOrder(0);
    cout << '\n';
    postOrder(0);
    cout << '\n';

    // inputFileStream.close();
    return 0;
}
