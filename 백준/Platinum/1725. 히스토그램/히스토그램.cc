#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;


int N;
int arr[100005];

int recursion(int start, int end) {
	if (start >= end) return arr[start];

	int mid = (start + end) / 2;
	int val = arr[mid];
	int s = mid;
	int e = mid;
	int h = arr[mid];

	while (s != start || e != end) {
	
		if (s == start) {
			if (arr[e + 1] < h) h = arr[e + 1];
			e = e + 1;
			val = max(val, (e - s + 1) * h);
		}
		else if (e == end) {
			if (arr[s - 1] < h) h = arr[s - 1];
			s = s - 1;
			val = max(val, (e - s + 1) * h);
		}
		else if (arr[s - 1] >= arr[e + 1]) {
			if (arr[s - 1] < h) h = arr[s - 1];
			s = s - 1;
			val = max(val, (e - s + 1) * h);
		}
		else if (arr[s - 1] < arr[e + 1]) {
			if (arr[e + 1] < h) h = arr[e + 1];
			e = e + 1;
			val = max(val, (e - s + 1) * h);
		}

	}

	return max(recursion(start, mid - 1), max(val, recursion(mid + 1, end)));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	
	int s = 1;
	int e = N;

	cout << recursion(1, N);

	
	return 0;

}