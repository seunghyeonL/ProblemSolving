#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <fstream>
#include <memory.h>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ans = 0;


int arr[6][6];
bool arrflag[6][6];
vector<int> record;

void dfs(int x, int y, int cnt) {

	ans = 10 * ans + arr[x][y];

	if (cnt == 6) {
		bool check = false;
		
		for (int i = 0; i < record.size(); i++) {
			if (record[i] == ans) {
				check = true;
				break;
			}
		}
		
		if (!check) record.push_back(ans);
		ans = (ans - arr[x][y]) / 10;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (x + dx[i] > 0 && x + dx[i] <= 5 && y + dy[i] > 0 && y + dy[i] <= 5) {
			dfs(x + dx[i], y + dy[i], cnt + 1);
		}
	}

	ans = (ans - arr[x][y]) / 10;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> arr[i][j]; 
		}
	}
	
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			dfs(i, j, 1);
		}
	}

	

	cout << record.size();

	return 0;
}