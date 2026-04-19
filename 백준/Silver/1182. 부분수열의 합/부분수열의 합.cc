#include <iostream>
#include <vector>

using namespace std;

int arr[21];

vector<int> sum;

int N, S;
int ans;

void recursion(int n) {
	int size;
	if (n == 1) {
		sum.push_back(0);
		sum.push_back(arr[0]);

		if (S == arr[0])
			ans++;
	}
	else {
		size = sum.size();
		for (int i = 0; i < size; i++) {
			if (sum[i] + arr[n - 1] == S)
				ans++;
			sum.push_back(sum[i] + arr[n-1]);
		}
	}

	if (n < N)
		recursion(n + 1);
	
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}	

	recursion(1);
	cout << ans;


	return 0;
}
