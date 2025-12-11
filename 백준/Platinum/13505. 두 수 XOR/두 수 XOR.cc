#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
const int BMX = 31; // 1e9 < 2^31
int N;
int arr[NMX];

int trie[BMX * NMX + 1][2];
int node_num;

void insert(int n)
{
    int cv = 0;

    for (int p = BMX - 1; p >= 0; p--)
    {
        int cb = (n >> p) & 1;

        if (trie[cv][cb])
        {
            cv = trie[cv][cb];
            continue;
        }

        trie[cv][cb] = ++node_num;
        cv = node_num;
    }
}

// 상위 비트 가 다른 경우가 있으면 같은 경우는 탐색 x
// 상위 비트가 같으면 하위 비트가 모두 달라도 더 작음
void bt(int cv1, int cv2, int p, int xor_val, int &mx_xor)
{
    if (p == -1)
    {
        mx_xor = max(mx_xor, xor_val);
        return;
    }

    bool move_higher_bit = false;
    if (trie[cv1][0] && trie[cv2][1])
    {
        bt(trie[cv1][0], trie[cv2][1], p - 1, xor_val + (1 << p), mx_xor);
        move_higher_bit = true;
    }

    if (trie[cv1][1] && trie[cv2][0])
    {
        bt(trie[cv1][1], trie[cv2][0], p - 1, xor_val + (1 << p), mx_xor);
        move_higher_bit = true;
    }

    if (move_higher_bit)
        return;

    if (trie[cv1][0] && trie[cv2][0])
        bt(trie[cv1][0], trie[cv2][0], p - 1, xor_val, mx_xor);

    if (trie[cv1][1] && trie[cv2][1])
        bt(trie[cv1][1], trie[cv2][1], p - 1, xor_val, mx_xor);
}

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
        cin >> arr[i];

    for (int i = 0; i < N; i++)
        insert(arr[i]);

    int ans = 0;
    bt(0, 0, BMX - 1, 0, ans);

    cout << ans;
    // inputFileStream.close();
    return 0;
}