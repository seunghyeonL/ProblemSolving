#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    string name;
	int N, k, name_len;
	queue<int> q[21];
	long long ans = 0;

	cin >> N >> k;
	for (int i = 0; i < N; i++) {
		cin >> name;

		name_len = name.size();

		while (!q[name_len].empty() && q[name_len].front() < i - k) {
			q[name_len].pop();
		}
		ans += q[name_len].size();
		q[name_len].push(i);
	}

	cout << ans;
}