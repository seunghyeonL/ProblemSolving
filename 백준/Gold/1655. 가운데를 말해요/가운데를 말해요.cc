#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<int> lpq;
priority_queue<int, vector<int>, greater<int>> rpq;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    cin >> N;

    {
        int n1;
        cin >> n1;
        cout << n1 << '\n';
        lpq.push(n1);

        int n2;
        cin >> n2;
        if (n2 >= n1)
        {
            rpq.push(n2);
            cout << n1 << '\n';
        }
        else
        {
            rpq.push(n1);
            lpq.pop();
            lpq.push(n2);
            cout << n2 << '\n';
        }
    }

    for (int i = 2; i < N; i++)
    {
        int n;
        cin >> n;

        int l = lpq.top();
        int r = rpq.top();

        if (l >= n)
        {
            lpq.push(n);
            if (lpq.size() > rpq.size() + 1)
            {
                rpq.push(lpq.top());
                lpq.pop();
            }
        }
        else if (r <= n)
        {
            rpq.push(n);
            if (lpq.size() < rpq.size())
            {
                lpq.push(rpq.top());
                rpq.pop();
            }
        }
        else
        {
            if (lpq.size() == rpq.size())
            {
                lpq.push(n);
            }
            else if (lpq.size() == rpq.size() + 1)
            {
                rpq.push(n);
            }
            else
            {
                for (int e = 0; e < 100; e++)
                {
                    cout << "!!!" << '\n';
                }
            }
        }

        cout << lpq.top() << '\n';
    }

    // inputFileStream.close();
    return 0;
}