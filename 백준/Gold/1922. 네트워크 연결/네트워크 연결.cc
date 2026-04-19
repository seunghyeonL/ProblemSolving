#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define pii pair<int, int>

int N, M;
int root[1001];
int ans;

vector<pii> cost[10001];

bool flag;

int F(int a){
	if(root[a]<0) return a;
	return root[a] = F(root[a]);
}
void U(int a, int b){
	int A = F(a);
	int B = F(b);
	if(A==B) return;
	root[B] += root[A];
	root[A] = B;
}
int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

cin >> N >> M;
for (int i = 1; i <= N; ++i) root[i] = -1;
for (int i = 0; i < M; ++i){
	int a, b, c;
	cin >> a >> b >> c;
	cost[c].push_back(pii(a,b));
}
for (int i = 0; i < 10001; ++i){
	if(flag) break;
	if(cost[i].empty())
		continue;
	for(int j=0; j<cost[i].size();++j){
		if(flag) break;
		int a = cost[i][j].first;
		int b = cost[i][j].second;
		
		if(F(a)==F(b)) continue;
		U(a,b);
		ans += i;		
		if(root[b]==-N)
			flag = true;
	}
}
cout << ans << '\n';

return 0;
}