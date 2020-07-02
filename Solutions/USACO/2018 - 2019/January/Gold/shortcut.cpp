#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, t, c[10001], pre[10001];
vector<pair<int, int>> adj[10001];
bool vis[10001];
long long dst[10001], cnt[10001];

bool compare(int a, int b, int edg){
	if(dst[a] != dst[b] + edg) return dst[a] > dst[b] + edg;
	else return pre[a] > b;
}

int main(){
	IO("shortcut.in", "shortcut.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back(make_pair(b, w));
		adj[b].push_back(make_pair(a, w));
	}
	priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> que;
	for(int i = 1; i <= n; i++)
		dst[i] = pre[i] = 2e9;
	dst[1] = pre[1] = 0;
	que.push(make_pair(0, 1));
	while(!que.empty()){
		int vtx = que.top().second;
		que.pop();
		if(vis[vtx]) continue;
		vis[vtx] = true;
		for(auto &i : adj[vtx])
			if(compare(i.first, vtx, i.second)){
				dst[i.first] = dst[vtx] + i.second;
				pre[i.first] = vtx;
				que.push(make_pair(dst[i.first], i.first));
			}
	}
	for(int i = 1; i <= n; i++){
		int vtx = i;
		while(vtx)
			cnt[vtx] += c[i], vtx = pre[vtx];
	}
	long long ans = 0;
	for(int i = 2; i <= n; i++) ans = max(ans, (dst[i] - t) * cnt[i]);
	cout << ans << '\n';
	return 0;
}
