#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <climits>
using namespace std;


int N, M;
int arr[100005];
int k_pos;
int ans = INT_MAX;

bool check(int k) {
	int disk = 0;
	int cnt = 1;
	for (int i = 1; i <= N; i++) {
		if (arr[i] > k) return false;

		if(disk + arr[i] <= k)
			disk += arr[i];
		else {
			cnt++;
			disk = arr[i];
		}
	}
	if (cnt <= M) return true;
	else return false;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ifstream input("input.txt");

	cin >> N >> M;

	int sum=0;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	

	k_pos = sum;
	int k_min = sum / M;

	int s = k_min;
	int e = k_pos;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (check(mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else
			s = mid + 1;
	}

	cout << ans;

	return 0;

}
