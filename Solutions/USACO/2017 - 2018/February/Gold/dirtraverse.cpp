#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n;
long long val[100001], dp[100001][3];
vector<int> adj[100001];
bool file[100001];

pair<long long, int> getDown(int vtx, int pre){
	for(auto &i : adj[vtx])
		if(i != pre){
			pair<long long, int> down = getDown(i, vtx);
			dp[vtx][1] += down.second;
			dp[vtx][0] += down.first;
		}
	if(file[vtx]) return make_pair(val[vtx], 1);
	return make_pair(dp[vtx][0] + dp[vtx][1] * (val[vtx] + 1), dp[vtx][1]);
}

void getUp(int vtx, int pre, pair<long long, int> up){
	dp[vtx][2] = dp[vtx][0] + up.first;
	for(auto &i : adj[vtx])
		if(i != pre && !file[i]){
			long long alt2 = up.second + dp[vtx][1] - dp[i][1];
			long long alt1 = up.first + dp[vtx][0] - dp[i][0] - dp[i][1] * (val[i] + 1) + 3 * alt2;
			getUp(i, vtx, make_pair(alt1, alt2));
		}
}

int main(){
	IO("dirtraverse.in", "dirtraverse.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++){
		string str;
		int m;
		cin >> str >> m;
		val[i] = (int)str.length();
		for(int j = 0; j < m; j++){
			int vtx;
			cin >> vtx;
			adj[i].push_back(vtx);
		}
		if(!m) file[i] = true;
	}
	getDown(1, 0), getUp(1, 0, make_pair(0, 0));
	long long mn = LLONG_MAX;
	for(int i = 1; i <= n; i++)
		if(!file[i]) mn = min(mn, dp[i][2]);
	cout << mn << "\n";
	return 0;
}
