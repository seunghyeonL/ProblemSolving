#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <climits>
using namespace std;

int adj[13][13];
int edge_num[13];
int run(void) {
	for (int i = 1; i <= 12; i++) {
		bool one = false;
		bool two = false;
		bool three = false;

		if (edge_num[i] == 3) {
			for (int j = 1; j <= 12; j++) {
				if (adj[i][j] && edge_num[j] == 1) one = true;
				if (adj[i][j] && edge_num[j] == 2) two= true;
				if (adj[i][j] && edge_num[j] == 3) three = true;
			}
		}
		if (one && two && three) return i;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ifstream input("input.txt");

	for (int i = 0; i < 12; i++) {
		int x, y; // 1 <= x,y <= 12
	    cin >> x >> y;
		adj[x][y] = 1;
		adj[y][x] = 1;
		edge_num[x]++;
		edge_num[y]++;
	}

	int ans = run();

	cout << ans;

	return 0;


}

