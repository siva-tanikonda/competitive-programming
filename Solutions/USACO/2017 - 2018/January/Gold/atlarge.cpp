#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, k;
vector<int> adj[100001];

int dst[100001];
int lower(int vtx, int par){
	if((int)adj[vtx].size() == 1){
		dst[vtx] = 0;
		return 1;
	}else{
		dst[vtx] = INT_MAX;
		for(auto &i : adj[vtx])
			if(i != par) dst[vtx] = min(dst[vtx], lower(i, vtx));
		return dst[vtx] + 1;
	}
}
int chase(int vtx, int par, int time){
	if(dst[vtx] > time){
		int sum = 0;
		for(auto &i : adj[vtx])
			if(i != par) sum += chase(i, vtx, time + 1);
		return sum;
	}else return 1;
}

int main(){
	IO("atlarge.in", "atlarge.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	lower(k, 0);
	cout << chase(k, 0, 0) << "\n";
	return 0;
}