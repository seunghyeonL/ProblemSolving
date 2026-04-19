#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N, M;
int is_stack[NMX];
stack<int> st;
queue<int> q;

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
        cin >> is_stack[i];

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        if (!is_stack[i])
            st.push(n);
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;

        q.push(n);
        cout << q.front() << ' ';
        q.pop();
    }

    // inputFileStream.close();
    return 0;
}