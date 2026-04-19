#include <iostream>
#include <algorithm>

using namespace std;


int map[1001][1001];
int ans;
int N, M;
int dp[1001][1001];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int tmp;

	cin >> N >> M;
	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	/*
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = map[i][j] + max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
		}
	}
	/*
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	cout << dp[N][M];

	return 0;
}