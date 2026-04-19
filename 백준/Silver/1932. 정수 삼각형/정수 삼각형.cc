#include <iostream>
#include <algorithm>

using namespace std;


int line[501][501];
int ans;
int n;
int dp[501][501];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int tmp;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			
			cin >> line[i][j];
			
		}
	}
	
	dp[0][0] = line[0][0];
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j]+line[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1]+line[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + line[i][j];

		}
	}

	for (int i = 0; i < n; i++) {
		if (ans < dp[n-1][i]) ans = dp[n-1][i];
	}

	cout << ans;

	return 0;
}
