#include <bits/stdc++.h>
using namespace std;

constexpr int NMX = 100000;
int N;
int post[NMX];
int in[NMX];
int in_idx[NMX + 1];

void rec(int in_l, int in_r, int post_l, int post_r)
{
    if (in_l > in_r || post_l > post_r)
        return;

    int root = post[post_r];

    int in_root_idx = in_idx[root];

    int left_sub_tree_num = (in_root_idx - 1) - in_l + 1;
    int right_sub_tree_num = in_r - (in_root_idx + 1) + 1;

    cout << root << ' ';

    // left sub tree
    rec(in_l, in_root_idx - 1, post_l, post_l + left_sub_tree_num - 1);

    // right sub tree
    rec(in_root_idx + 1, in_r, post_r - 1 - right_sub_tree_num + 1, post_r - 1);
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
    {
        cin >> in[i];
        in_idx[in[i]] = i;
    }

    for (int i = 0; i < N; i++)
        cin >> post[i];

    rec(0, N - 1, 0, N - 1);

    // inputFileStream.close();
    return 0;
}