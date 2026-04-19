#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int vec[1048580];
	int N, k;
    int cnt = 0;
    int n=2;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}

	cin >> k;

	while (N/n >= k) {
		for (int i = 0; i < N/n; i++) {
			sort(vec + cnt, vec + cnt + n);
			cnt = cnt + n;
		}
		cnt = 0;
		n = n * 2;
	}
	
	for (int i = 0; i < N; i++) {
		cout << vec[i] << ' ';
	}

	return 0;
}