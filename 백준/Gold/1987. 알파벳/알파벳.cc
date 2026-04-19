#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <fstream>
#include <memory.h>
using namespace std;

int R, C;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ans = 0;


char rc[21][21] = { 0, };
bool rcflag[21][21] = { false, };
vector<char> record;

void dfs(int x, int y) {
	bool check = false;
	for (int i = 0; i < record.size(); i++) {
		if (record[i] == rc[x][y]) {
			check = true;
			break;
		}
	}
	if (!check) {
		record.push_back(rc[x][y]);
		if (ans < record.size()) ans = record.size();
	}
	else return;

	for (int i = 0; i < 4; i++) {
		if (x+dx[i]>0 && x+dx[i] <= R && y+dy[i] >0 && y+dy[i] <= C) {
			if (!rcflag[x + dx[i]][y + dy[i]]) {
				rcflag[x + dx[i]][y + dy[i]] = true;
				dfs(x + dx[i], y + dy[i]);
				rcflag[x + dx[i]][y + dy[i]] = false;
			}
		}
	}

	record.pop_back();

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
    cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> rc[i][j]; 
		}
	}
	
	dfs(1, 1);


	cout << ans;

	return 0;
}