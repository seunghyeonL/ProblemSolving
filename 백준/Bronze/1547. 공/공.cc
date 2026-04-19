#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> v = { 1, 0, 0 };
	int M;
	int a, b, tmp;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		tmp = v[b-1];
		v[b-1] = v[a-1];
		v[a-1] = tmp;
	}
	for (int i = 0; i < 3; i++)
		if (v[i] == 1) cout << i + 1;
	
	return 0;
}