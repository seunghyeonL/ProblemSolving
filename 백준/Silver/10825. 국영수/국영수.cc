#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct student {
	string name;
	int kor, eng, math;
};

bool compare(student a, student b);

vector<student> ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	student now;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> now.name >> now.kor >> now.eng >> now.math;
		ans.push_back(now);
	}
	
	sort(ans.begin(), ans.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << ans[i].name << '\n';
	}
		
	return 0;
	
}

bool compare(student a, student b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math)
				return a.name < b.name;
			else
				return a.math > b.math;
		}
		else
			return a.eng < b.eng;
	}
	else
		return a.kor > b.kor;
}