#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <climits>
using namespace std;


int N, r, c;

int uncom;
int ans;

void z_run(int x, int y, int size) {
	if (ans != 0) return;
	
	if (x == r && y == c) {
		ans = uncom;
		return;
	}
	
	if (size == 1) {
		uncom++;
		return;
	}

	if (r >= x && r <= x + size && c >= y && c <= y + size) {
		z_run(x, y, size / 2);
		z_run(x, y + size / 2, size / 2);
		z_run(x + size / 2, y, size / 2);
		z_run(x + size / 2, y + size / 2, size / 2);
	}
	else uncom += size * size;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> r >> c;

	int size_ini = 1;

	for (int i = 0; i < N; i++) {
		size_ini *= 2;
	}

	z_run(0, 0, size_ini);

	cout << ans;

	return 0;

}
