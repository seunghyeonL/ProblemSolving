#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int desx, desy;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };



int arr[1005][1005];
int dist[1005][1005];

queue<pair<int, int>> q;


void bfs(int x, int y) {
	
	q.push({ x, y });
	dist[x][y] = 0;

	
	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second;
		q.pop();
		
		int nx, ny;
			   
		for (int i = 0; i < 4; i++) {
			nx = px + dx[i];
			ny = py + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
				if (arr[nx][ny] != 0) {
                    if (dist[nx][ny] == -1) {
		    			dist[nx][ny] = dist[px][py] + 1;
		    			q.push({ nx, ny });
		    		}
                }
			}
			
		}

	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    memset(dist, -1, 1005 * 1005 * sizeof(int));

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				desx = i;
				desy = j;
			}
            if(arr[i][j] == 0) dist[i][j] = 0;
		}
	}
	
	bfs(desx, desy);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dist[i][j] << ' ';

		}
		cout << '\n';
	}

	return 0;
}