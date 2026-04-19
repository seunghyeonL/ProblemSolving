#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	bool isone = false;
	int N, tmp;
	int sum = 0;
	vector<int> wgt, able;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		wgt.push_back(tmp);
		if (tmp == 1) isone = true;
	}

	if (!isone) {
		cout << 1;
		return 0;
	}

	sort(wgt.begin(), wgt.end());

	for (int i = 0; i < N; i++) {
		if (wgt[i] > sum + 1) break;
		sum += wgt[i];
	}
	cout << sum + 1;
	return 0;

}