#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

stack<vector<int>> order;
stack<string> ans;
int originParents[200001];
int N, Q;

int parents[200001];

void parentsInit()
{
	for (int i = 1; i <= N; i++)
	{
		parents[i] = i;
		originParents[i] = i;
	}
}

int getParent(int a)
{
	if (parents[a] == a) return a;
	else return parents[a] = getParent(parents[a]);
}

void UNION(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	parents[b] = a;
}

void Input()
{
	cin >> N >> Q;
	parentsInit();
	for (int i = 2; i < (N - 1) + 2; i++)
		cin >> originParents[i];

	int x, b, c, d;
	for (int i = 0; i < (N - 1) + Q; i++)
	{
		vector<int> question;
		cin >> x;
		question.push_back(x);

		if (x == 0)
		{
			cin >> b;
			question.push_back(b);
		}
		else
		{
			cin >> c >> d;
			question.push_back(c);
			question.push_back(d);
		}
		order.push(question);
	}
}

void Solve()
{
	while (!order.empty())
	{
		vector<int>question = order.top();
		order.pop();
		int b, c, d;
		if (question[0] == 0)
		{
			b = question[1];
			parents[b] = originParents[b];
		}
		else
		{
			c = question[1];
			d = question[2];

			if (getParent(c) == getParent(d))
				ans.push("YES");
			else
				ans.push("NO");
		}
	}

	while(!ans.empty())
	{
		cout << ans.top() << '\n';
		ans.pop();
	}
}

int main()
{
	Input();
	Solve();
	
	return 0;
}