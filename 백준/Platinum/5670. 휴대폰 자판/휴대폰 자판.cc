#include <bits/stdc++.h>
using namespace std;

const int LMT = 1000000;
int N;
int trie[LMT + 1][26];
int node_num;
bool is_end[LMT + 1];
int W[LMT + 1]; // 현재 노드 서브트리의 endpoint 개수

int c2i(char c)
{
    return c - 'a';
}

char i2c(int i)
{
    return i + 'a';
}

void reset()
{
    for (int i = 0; i <= LMT; i++)
        fill(trie[i], trie[i] + 26, 0);

    node_num = 0;
    fill(is_end, is_end + LMT + 1, false);
    fill(W, W + LMT + 1, 0);
}

void insert(const string &str)
{
    int cv = 0;

    for (char c : str)
    {
        int i = c2i(c);

        if (trie[cv][i])
        {
            cv = trie[cv][i];
            continue;
        }

        trie[cv][i] = ++node_num;
        cv = node_num;
    }

    is_end[cv] = true;
}

void set_W(int cv)
{
    if (is_end[cv])
        W[cv]++;

    for (int i = 0; i < 26; i++)
    {
        int nv = trie[cv][i];
        if (nv == 0)
            continue;

        set_W(nv);
        W[cv] += W[nv];
    }
}

int get_push_num(const string &str)
{
    int ret = 1;
    int cv = 0;
    for (char c : str)
    {
        int i = c2i(c);

        int nv = trie[cv][i];
        if (cv > 0 && W[nv] < W[cv])
            ret++;

        cv = nv;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    while (cin >> N)
    {
        reset();

        vector<string> arr;

        for (int i = 0; i < N; i++)
        {
            string str;
            cin >> str;

            arr.push_back(str);
            insert(str);
        }

        set_W(0);
        int push_num = 0;

        for (const string &str : arr)
        {
            push_num += get_push_num(str);
        }

        double ans = (double)push_num / N;

        cout << fixed;
        cout.precision(2);
        cout << ans << '\n';
    }

    // inputFileStream.close();
    return 0;
}