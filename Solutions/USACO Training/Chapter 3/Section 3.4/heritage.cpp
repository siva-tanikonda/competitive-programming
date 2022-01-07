/*
ID: siva.ja1
TASK: heritage
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

string pre, in, post;
map<char, pair<int, char>> par;
map<char, vector<char>> adj;

void dfs(char vtx){
	for(auto &i : adj[vtx]) dfs(i);
	post += vtx;
}

int main(){
	IO("heritage.in", "heritage.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> in >> pre;
	bool right = false;
	for(auto &i : in)
		if(i == pre[0]) right = true;
		else par[i] = {right, pre[0]};
	for(int i = 1; i < (int)pre.size(); i++){
		right = false;
		for(auto &j : in)
			if(par[j] == par[pre[i]]){
				if(j == pre[i]) right = true;
				else par[j] = {right, pre[i]};
			}
	}
	for(int i = 0; i < 2; i++)
		for(auto &j : par)
			if(j.second.first == i)
				adj[j.second.second].push_back(j.first);
	dfs(pre[0]);
	cout << post << "\n";
	return 0;
}