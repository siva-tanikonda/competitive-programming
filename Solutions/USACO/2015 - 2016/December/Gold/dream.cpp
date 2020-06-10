#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, adj[1000][1000];

bool bounds(int a, int b, int c){
	return (a >= 0 && a < n && b >= 0 && b < m && adj[a][b] != 0 && (adj[a][b] != 3 || c == 1));
}

bool vis[1000][1000][2];
int dst[1000][1000][2];
int main(){
	IO("dream.in", "dream.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) cin >> adj[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			for(int k = 0; k < 2; k++) dst[i][j][k] = INT_MAX;
	priority_queue<tuple<int, int, int, int>> que;
	dst[0][0][0] = 0;
	que.push(make_tuple(0, 0, 0, 0));
	int aa[] = {-1, 0, 1, 0}, bb[] = {0, -1, 0, 1};
	while(!que.empty()){
		int x, a, b, c;
		tie(x, a, b, c) = que.top();
		que.pop();
		if(vis[a][b][c]) continue;
		vis[a][b][c] = true;
		for(int i = 0; i < 4; i++){
			int na = a + aa[i], nb = b + bb[i], nc = c, add = 1;
			if(!bounds(na, nb, c)) continue;
			if(adj[na][nb] == 4){
				while(adj[na][nb] == 4 && bounds(na + aa[i], nb + bb[i], c))
					na += aa[i], nb += bb[i], add++;
			}
			if(adj[na][nb] == 2) nc = 1;
			if(dst[na][nb][nc] == INT_MAX || dst[na][nb][nc] > dst[a][b][c] + add){
				dst[na][nb][nc] = dst[a][b][c] + add;
				que.push(make_tuple(-dst[na][nb][nc], na, nb, nc));
			}
		}
	}
	if(dst[n - 1][m - 1][0] == INT_MAX && dst[n - 1][m - 1][1] == INT_MAX) cout << "-1\n";
	else cout << min(dst[n - 1][m - 1][0], dst[n - 1][m - 1][1]) << "\n";
	return 0;
}