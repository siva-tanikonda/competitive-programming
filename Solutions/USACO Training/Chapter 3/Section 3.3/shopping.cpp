/*
ID: siva.ja1
TASK: shopping
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, dsc[104][1000], res[1000][2];
map<vector<int>, int> dst;
map<vector<int>, bool> vis;

int main(){
	IO("shopping.in", "shopping.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m;
	for(int i = 0; i < m; i++){
		int cnt;
		cin >> cnt;
		for(int j = 0; j < cnt; j++){
			int a, b;
			cin >> a >> b;
			dsc[i][a] += b;
		}
		cin >> dsc[i][0];
	}
	cin >> n;
	vector<int> want(5, 0);
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		res[a][0] = want[i] = b;
		res[a][1] = i;
		dsc[i + m][a]++, dsc[i + m][0] = c;
	}
	vector<vector<int>> ops;
	for(int i = 0; i < n + m; i++){
		bool add = true;
		vector<int> ins(6, 0);
		ins[0] = dsc[i][0];
		for(int j = 1; j < 1000; j++)
			if(dsc[i][j] && !res[j]) add = false;
			else if(dsc[i][j]) ins[res[j][1] + 1] = dsc[i][j];
		if(add) ops.push_back(ins);
	}
	priority_queue<pair<int, vector<int>>> que;
	vector<int> sta = {0, 0, 0, 0, 0};
	que.push({0, sta});
	dst[sta] = 0;
	while(!que.empty()){
		vector<int> arr = que.top().second;
		que.pop();
		if(vis[arr]) continue;
		vis[arr] = true;
		for(auto &i : ops){
			vector<int> cpy = arr;
			bool val = true;
			for(int j = 0; j < 5; j++){
				cpy[j] += i[j + 1];
				if(cpy[j] > 5) val = false;
			}
			if(val && (dst.find(cpy) == dst.end() || dst[cpy] > dst[arr] + i[0])){
				dst[cpy] = dst[arr] + i[0];
				que.push({-dst[cpy], cpy});
			}
		}
	}
	cout << dst[want] << "\n";
	return 0;
}