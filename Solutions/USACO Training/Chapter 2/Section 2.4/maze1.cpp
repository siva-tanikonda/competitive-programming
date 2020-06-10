/*
ID: siva.ja1
TASK: maze1
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

int n, m;
string adj[201];

int main(){
	IO("maze1.in", "maze1.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n, getline(cin, adj[0]);
	vector<pair<int, int>> sta;
    for(int i = 0; i < 2 * n + 1; i++){
    	getline(cin, adj[i]);
    	if(adj[i][2 * m] == ' ') sta.push_back({i, 2 * m});
    	if(adj[i][0] == ' ') sta.push_back({i, 0});
    	if(i == 0 || i == 2 * n)
    		for(int j = 0; j < 2 * m + 1; j++)
    			if(adj[i][j] == ' ') sta.push_back({i, j});
    }
    vector<vector<vector<int>>> vis(2 * n + 1, vector<vector<int>>(2 * m + 1, vector<int>(2, INT_MAX)));
    int nn[] = {-1, 0, 1, 0}, mm[] = {0, -1, 0, 1};
    for(int i = 0; i < 2; i++){
    	queue<tuple<int, int, int>> que;
    	que.push({sta[i].first, sta[i].second, 0});
    	vis[sta[i].first][sta[i].second][i] = 0;
    	while(!que.empty()){
    		int a, b, c;
    		tie(a, b, c) = que.front();
    		que.pop();
    		for(int j = 0; j < 4; j++){
    			int na = a + nn[j], nb = b + mm[j];
    			if(na >= 0 && na < 2 * n + 1 && nb >= 0 && nb < 2 * m + 1 && adj[na][nb] == ' ' && vis[na][nb][i] == INT_MAX){
    				vis[na][nb][i] = c + 1;
    				que.push({na, nb, c + 1});
    			}
    		}
    	}
    }
    int mx = 0;
    for(int i = 0; i < 2 * n + 1; i++)
    	for(int j = 0; j < 2 * m + 1; j++)
    		if(vis[i][j][0] != INT_MAX || vis[i][j][1] != INT_MAX) mx = max(mx, min(vis[i][j][0], vis[i][j][1]));
    cout << ((mx + 1) / 2) << "\n";
	return 0;
}