#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n;
pair<int, int> crd[1000];
bool vis[1000];

int main(){
	IO("moocast.in", "moocast.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> crd[i].first >> crd[i].second;
	int l = 0, r = (int)2e9;
	for(int k = 0; k < 50; k++){
		int mid = l + (r - l) / 2;
		queue<int> que;
		que.push(0), vis[0] = true;
		while(!que.empty()){
			int vtx = que.front();
			que.pop();
			for(int i = 0; i < n; i++){
				int dst = abs(crd[vtx].first - crd[i].first) * abs(crd[vtx].first - crd[i].first) + abs(crd[vtx].second - crd[i].second) * abs(crd[vtx].second - crd[i].second);
				if(!vis[i] && dst <= mid){
					vis[i] = true;
					que.push(i);
				}
			}
		}
		bool val = true;
		for(int i = 0; i < n; i++)
			if(!vis[i]) val = false;
		if(val) r = mid;
		else l = mid + 1;
		for(int i = 0; i < n; i++) vis[i] = false;
	}
	cout << r << "\n";
	return 0;
}