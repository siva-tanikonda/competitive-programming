#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, dst[100001];
map<int, int> mp;

void update(int a, int b){
	auto it = prev(mp.upper_bound(a));
	if((it -> second) <= b) return;
	it++;
	while(it != mp.end() && (it -> second) > b) mp.erase(it++);
	mp[a] = b;
}

int main(){
	IO("boards.in", "boards.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	mp[0] = 0;
	vector<pair<pair<int, int>, pair<int, int>>> spr;
	for(int i = 0; i < m; i++){
		pair<int, int> a, b;
		cin >> a.first >> a.second >> b.first >> b.second;
		spr.push_back({a, {i, -1}});
		spr.push_back({b, {i, 1}});
	}
	sort(spr.begin(), spr.end());
	for(auto &i : spr)
		if(i.second.second == -1){
			int add = prev(mp.upper_bound(i.first.second)) -> second;
			dst[i.second.first] = i.first.first + i.first.second + add;
		}else update(i.first.second, dst[i.second.first] - i.first.first - i.first.second);
	cout << ((mp.rbegin() -> second) + 2 * n) << "\n";
	return 0;
}
