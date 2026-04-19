#include <iostream>
#include <deque>

int arr[1000005];

using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tmp;

	deque<int> deq;
	deque<int>::reverse_iterator it;
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		switch (arr[i])
		{
			case 1:
				deq.push_back(N - i);
				break;
			case 2:
				tmp = deq.back();
				deq.pop_back();
				deq.push_back(N - i);
				deq.push_back(tmp);
				break;
			case 3:
				deq.push_front(N - i);
				break;
			default:
				break;
		}
	}
	
	for (it = deq.rbegin(); it != deq.rend(); it++) {
		cout << *it << ' ';
	}


	return 0;
}