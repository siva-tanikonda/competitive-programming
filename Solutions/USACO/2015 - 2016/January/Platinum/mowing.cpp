#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace __gnu_pbds;
using namespace std;

const int sz = 400;
int n, t, x[100000], y[100000], rec[100001];
vector<int> arr[100001];

void remove(int time, int pos){
	auto it = lower_bound(arr[time / sz].begin(), arr[time / sz].end(), pos);
	arr[time / sz].erase(it);
	rec[time] = -1;
}

void add(int time, int pos){
	arr[time / sz].push_back(pos);
	sort(arr[time / sz].begin(), arr[time / sz].end());
	rec[time] = pos;
}

long long query(int tl, int tr, int l, int r){
	long long res = 0;
	for(int i = tl; i <= tr;)
		if(i % sz == 0 && i + sz - 1 <= tr){
			auto it1 = upper_bound(arr[i / sz].begin(), arr[i / sz].end(), r) - 1;
			auto it2 = lower_bound(arr[i / sz].begin(), arr[i / sz].end(), l) - 1;
			res += it1 - it2;
			i += sz;
		}else{
			res += (rec[i] >= l && rec[i] <= r);
			i++;
		}
	return res;
}

int main(){
	IO("mowing.in", "mowing.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> t;
	map<int, vector<tuple<int, int, int>>> qy;
	map<int, vector<pair<int, int>>> rx, ax;
	set<int> ux;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		if(i){
			if(x[i] == x[i - 1]){
				int a = min(y[i], y[i - 1]);
				int b = max(y[i], y[i - 1]);
				int c = i + 1;
				qy[x[i]].push_back(make_tuple(a, b, c));
			}else{
				int a = min(x[i], x[i - 1]);
				int b = max(x[i], x[i - 1]);
				int c = i + 1;
				ax[a].push_back(make_pair(y[i], c));
				rx[b].push_back(make_pair(y[i], c));
			}
		}
		ux.insert(x[i]);
	}
	long long ans = 0;
	fill(rec, rec + n + 1, -1);
	for(auto &i : ux){
		for(auto &j : rx[i]) remove(j.second, j.first);
		for(auto &j : qy[i]){
			int a, b, c;
			tie(a, b, c) = j;
			ans += query(1, c - t, a + 1, b - 1);
			ans += query(c + t, n, a + 1, b - 1);
		}
		for(auto &j : ax[i]) add(j.second, j.first);
	}
	cout << ans << '\n';
	return 0;
}