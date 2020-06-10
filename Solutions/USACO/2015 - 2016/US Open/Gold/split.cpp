#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n;
long long mn[50002][2], mx[50002][2];
pair<long long, long long> crd[50001];

int main(){
	IO("split.in", "split.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	long long l = INT_MAX, r = INT_MIN, t = INT_MIN, b = INT_MAX;
	vector<pair<long long, long long>> x = {{-1, -1}}, y = {{-1, 1}};
	for(int i = 1; i <= n; i++){
		cin >> crd[i].first >> crd[i].second;
		x.push_back(crd[i]);
		y.push_back({crd[i].second, crd[i].first});
		l = min(crd[i].first, l);
		r = max(crd[i].first, r);
	    b = min(crd[i].second, b);
	    t = max(crd[i].second, t);
	}
	long long cur = (t - b) * (r - l);
	sort(x.begin(), x.end()), sort(y.begin(), y.end());
	long long best = LLONG_MAX;
	mn[n + 1][1] = mn[0][0] = LLONG_MAX;
	mx[n + 1][1] = mx[0][0] = 0;
	for(int i = 1; i <= n; i++){
		mn[i][0] = min(mn[i - 1][0], x[i].second);
		mx[i][0] = max(mx[i - 1][0], x[i].second);
	}
	for(int i = n; i >= 1; i--){
		mn[i][1] = min(mn[i + 1][1], x[i].second);
		mx[i][1] = max(mx[i + 1][1], x[i].second);
	}
	for(int i = 1; i < n; i++){
		long long rec1 = (x[i].first - l) * (mx[i][0] - mn[i][0]);
		long long rec2 = (r - x[i + 1].first) * (mx[i + 1][1] - mn[i + 1][1]);
		if(x[i].first != x[i + 1].first) best = min(best, rec1 + rec2);
	}
	mn[n + 1][1] = mn[0][0] = LLONG_MAX;
	mx[n + 1][1] = mx[0][0] = 0;
	for(int i = 1; i <= n; i++){
		mn[i][0] = min(mn[i - 1][0], y[i].second);
		mx[i][0] = max(mx[i - 1][0], y[i].second);
	}
	for(int i = n; i >= 1; i--){
		mn[i][1] = min(mn[i + 1][1], y[i].second);
		mx[i][1] = max(mx[i + 1][1], y[i].second);
	}
	for(int i = 1; i < n; i++){
		long long rec1 = (y[i].first - b) * (mx[i][0] - mn[i][0]);
		long long rec2 = (t - y[i + 1].first) * (mx[i + 1][1] - mn[i + 1][1]);
		if(y[i].first != y[i + 1].first) best = min(best, rec1 + rec2);
	}
	cout << cur - best << "\n";
	return 0;
}