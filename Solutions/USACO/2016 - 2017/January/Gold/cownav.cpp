#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n, vis[20][20][20][20][4][4];
string arr[20];

bool bounds(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 'E');
}

int main(){
	IO("cownav.in", "cownav.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int xx[] = {-1, 0, 1, 0}, yy[] = {0, 1, 0, -1};
	queue<tuple<int, int, int, int, int, int, int>> que;
	que.push(make_tuple(n - 1, 0, n - 1, 0, 0, 1, 1));
	vis[n - 1][0][n - 1][0][0][1] = 1;
	while(!que.empty()){
		int a, b, c, d, e, f, g;
		tie(a, b, c, d, e, f, g) = que.front();
		que.pop();
		if(!vis[a][b][c][d][(e + 1) % 4][(f + 1) % 4]){
			vis[a][b][c][d][(e + 1) % 4][(f + 1) % 4] = g + 1;
			que.push(make_tuple(a, b, c, d, (e + 1) % 4, (f + 1) % 4, g + 1));
		}
		int e2 = e - 1, f2 = f - 1;
		if(e2 < 0) e2 = 3;
		if(f2 < 0) f2 = 3;
		if(!vis[a][b][c][d][e2][f2]){
			vis[a][b][c][d][e2][f2] = g + 1;
			que.push(make_tuple(a, b, c, d, e2, f2, g + 1));
		}
		for(int i = 0; i < 4; i++){
			int x1 = a + xx[e], y1 = b + yy[e], x2 = c + xx[f], y2 = d + yy[f];
			if(!bounds(x1, y1) || (a == 0 && b == n - 1)) x1 = a, y1 = b;
			if(!bounds(x2, y2) || (c == 0 && d == n - 1)) x2 = c, y2 = d;
			if(!vis[x1][y1][x2][y2][e][f]){
				vis[x1][y1][x2][y2][e][f] = g + 1;
				que.push(make_tuple(x1, y1, x2, y2, e, f, g + 1));
			}
		}
	}
	int mn = INT_MAX;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(vis[0][n - 1][0][n - 1][i][j]) mn = min(mn, vis[0][n - 1][0][n - 1][i][j]);
	cout << mn - 1 << "\n";
	return 0;
}