/*
ID: siva.ja1
TASK: ttwo
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

string adj[10];
bool vis[10][10][4][10][10][4];

int main(){
	IO("ttwo.in", "ttwo.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a = -1, b = -1, c = 0, d = -1, e = -1, f = 0;
	for(int i = 0; i < 10; i++){
		cin >> adj[i];
		for(int j = 0; j < 10; j++)
			if(adj[i][j] == 'F') a = i, b = j;
			else if(adj[i][j] == 'C') d = i, e = j;
	}
	int nn[4] = {-1, 0, 1, 0}, mm[4] = {0, 1, 0, -1}, cnt = 0;
	while((a != d || b != e) && !vis[a][b][c][d][e][f]){
		vis[a][b][c][d][e][f] = true;
		int na = a + nn[c], nb = b + mm[c], nd = d + nn[f], ne = e + mm[f];
		if(na >= 0 && na < 10 && nb >= 0 && nb < 10 && adj[na][nb] != '*') a = na, b = nb;
		else c = (c + 1) % 4;
		if(nd >= 0 && nd < 10 && ne >= 0 && ne < 10 && adj[nd][ne] != '*') d = nd, e = ne;
		else f = (f + 1) % 4;
		cnt++;
	}
	cout << ((a == d && b == e) ? cnt : 0) << "\n";
	return 0;
}