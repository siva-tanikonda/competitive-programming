#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n;
bool vis[100][100][3];
long long t, arr[100][100], dst[100][100][3];

bool bounds(int i, int j, int tri){
	return (i >= 0 && i < n && j >= 0 && j < n && !vis[i][j][tri]);
}

int main(){
	IO("visitfj.in", "visitfj.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> t;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
			for(int k = 0; k < 3; k++) dst[i][j][k] = LLONG_MAX;
		}
	priority_queue<tuple<long long, int, int, int>> que;
	que.push(make_tuple(0, 0, 0, 0));
	dst[0][0][0] = 0;
	int ii[] = {-1, 0, 1, 0}, jj[] = {0, -1, 0, 1};
	while(!que.empty()){
		long long d;
		int tri, i, j;
		tie(d, tri, i, j) = que.top();
		que.pop();
		if(vis[i][j][tri]) continue;
		vis[i][j][tri] = true;
		d *= -1;
		tri = (tri + 1) % 3;
		for(int k = 0; k < 4; k++){
			int ni = i + ii[k], nj = j + jj[k];
			if(bounds(ni, nj, tri)){
				long long nd = d + (tri == 0) * arr[ni][nj] + t;
				if(dst[ni][nj][tri] > nd){
					dst[ni][nj][tri] = nd;
					que.push(make_tuple(-nd, tri, ni, nj));
				}
			}
		}
	}
	long long mn = LLONG_MAX;
	for(int i = 0; i < 3; i++) mn = min(mn, dst[n - 1][n - 1][i]);
	cout << mn << "\n";
	return 0;
}