#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> circle, vtmp, ans;
	vector<int>::iterator it;
	int N, K, mod, pick;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		circle.push_back(i);
	}

	while ((int)circle.size() != 0) {

		mod = K % (int)circle.size();
		if (mod != 0) {
			pick = mod;
		}
		else {
			pick = circle.size();
		}

		ans.push_back(circle[pick-1]);

		vtmp.insert(vtmp.begin(), circle.begin() + pick, circle.end());
		vtmp.insert(vtmp.end(), circle.begin(), circle.begin() + pick - 1);
		//		for(it = vtmp.begin();it != vtmp.end();it++)
		//			cout << *it << ' ';
		circle.assign(vtmp.begin(), vtmp.end());
		vtmp.assign(vtmp.begin(), vtmp.begin());
		//		for (it = circle.begin(); it != circle.end(); it++)
		//			cout << *it << ' ';

		//		cout << '\n';

	}

	
	cout << '<';
	for (int i = 0; i < N; i++) {
		cout << ans[i];
		if (i == N - 1) break;
		cout << ',' << ' ';

	}
	cout << '>';

	return 0;
}
