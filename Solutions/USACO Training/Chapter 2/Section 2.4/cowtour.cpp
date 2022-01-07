/*
ID: siva.ja1
TASK: cowtour
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const double pi = 3.14159265358979;

int n;
double x[150], y[150];

double dist(int a, int b){
	return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

double getDiameter(int vtx, int mrk, vector<double> &far, vector<double> &vis, vector<vector<double>> &adj){
	vis[vtx] = mrk;
	double mx = far[vtx];
	for(int i = 0; i < n; i++)
		if(vis[i] == -1 && adj[vtx][i] != -1) mx = max(mx, getDiameter(i, mrk, far, vis, adj));
	return mx;
}

int main(){
	IO("cowtour.in", "cowtour.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	vector<vector<double>> adj(n, vector<double>(n, -1));
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < n; j++){
			bool cur = str[j] - '0';
			if(cur || i == j) adj[i][j] = dist(i, j);
		}
	}
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(adj[i][k] != -1 && adj[k][j] != -1 && (adj[i][j] == -1 || adj[i][j] > adj[i][k] + adj[k][j]))
					adj[i][j] = adj[i][k] + adj[k][j];
	vector<double> far(n, 0);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			far[i] = max(far[i], adj[j][i]);
	vector<double> vis(n, -1), res(n, 0);
	for(int i = 0; i < n; i++)
		if(vis[i] == -1){
			double dam = getDiameter(i, i, far, vis, adj);
			for(int j = 0; j < n; j++)
				if(vis[j] == i) res[j] = dam;
		}
	double mn = DBL_MAX;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(adj[i][j] == -1) mn = min(mn, max(dist(i, j) + far[i] + far[j], max(res[i], res[j])));
	cout << fixed << setprecision(6) << mn << "\n";
	return 0;
}