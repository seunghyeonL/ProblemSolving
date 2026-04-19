#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int MAX = INT_MAX;

int object[101] = { 0, };

int N, M;

int dp[101][101];

int recursion(int cp, int curr) {
	if (curr > N) return 0;

	if (object[curr])	dp[curr][cp] = recursion(cp, curr + 1);
	

	if (dp[curr][cp] != MAX) return dp[curr][cp];

	dp[curr][cp] = min(dp[curr][cp], recursion(cp, curr + 1)+10000);
	dp[curr][cp] = min(dp[curr][cp], recursion(cp + 1, curr + 3)+25000);
	dp[curr][cp] = min(dp[curr][cp], recursion(cp + 2, curr + 5)+37000);
	
	if (cp >= 3) dp[curr][cp] = min(dp[curr][cp], recursion(cp - 3, curr + 1));

	return dp[curr][cp];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int tmp;
	
	fill(&dp[0][0], &dp[0][0] + 101 * 101, MAX);

	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		object[tmp] = 1;
	}

		
	recursion(0, 1);

	cout << dp[1][0];

	return 0;
}