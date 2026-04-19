#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int MAX = INT_MAX;

int T;

int dp[12];

int recursion(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	if (dp[n] != 0) return dp[n];
	else dp[n] = recursion(n - 1) + recursion(n - 2) + recursion(n - 3);
	return dp[n];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	fill(dp, dp + 12, 0);
	cin >> T;
	
	
	for (int i = 0; i < T; i++) {
		cin >> n;
		
		cout << recursion(n) << '\n';
	}

	
	return 0;
}