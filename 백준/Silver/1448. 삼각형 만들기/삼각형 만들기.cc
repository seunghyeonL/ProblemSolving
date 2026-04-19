#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, tmp;
	int arr[1000005];
	int n = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}

	sort(arr, arr + N, compare);

	while (n < N-2) {
		if (arr[n] < arr[n + 1] + arr[n + 2]) break;
		n++;
	}

	if (n == N - 2)
		cout << -1;
	else
		cout << arr[n] + arr[n + 1] + arr[n + 2];

	return 0;
}

bool compare(int a, int b) {
	return a > b;
}