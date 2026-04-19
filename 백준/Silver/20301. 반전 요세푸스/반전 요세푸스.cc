#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt_k = 1;
	int cnt_m = 0;
	bool swt = true;
	int N, K, M, tmp;

	deque<int> dq;
	deque<int> ans;

	cin >> N >> K >> M;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	while (!dq.empty()) {
		if (cnt_m == M) {
			cnt_m = 0;
			swt = !swt;
		}

		if (swt) {
			if (cnt_k != K) {
				tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
				cnt_k++;
			}
			else {
				tmp = dq.front();
				dq.pop_front();
				ans.push_back(tmp);
				cnt_k = 1;
				cnt_m++;
			}
		}
		else {
			if (cnt_k != K) {
				tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
				cnt_k++;
			}
			else {
				tmp = dq.back();
				dq.pop_back();
				ans.push_back(tmp);
				cnt_k = 1;
				cnt_m++;
			}
		}



	}	


	while (!ans.empty()) {
		cout << ans.front() << ' ';
		ans.pop_front();
	}

	return 0;
}