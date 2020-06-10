#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

struct union_find{
	vector<int> par;
	void init(int n) { par = vector<int>(n, -1); }
	int find(int x) { return (par[x] < 0) ? x : par[x] = find(par[x]); }
	int size(int x) { return -par[find(x)]; }
	void unite(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		if(size(a) < size(b)) swap(a, b);
		par[a] += par[b], par[b] = a;
	}
};

int n, m;
long long x[2002], y[2002];

int f(int i, int j){ return i * (m + 1) + j; }

int main(){
	IO("fencedin.in", "fencedin.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p, q;
	cin >> p >> q >> n >> m;
	x[n + 1] = p, y[m + 1] = q;
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 1; i <= m; i++) cin >> y[i];
	sort(x, x + n + 1), sort(y, y + m + 1);
	vector<tuple<long long, int, int>> pri;
	for(int i = 0; i <= n; i++) pri.push_back(make_tuple(x[i + 1] - x[i], 0, i));
	for(int i = 0; i <= m; i++) pri.push_back(make_tuple(y[i + 1] - y[i], 1, i));
	sort(pri.begin(), pri.end());
	union_find dsu;
	dsu.init((n + 1) * (m + 1));
	long long res = 0;
	for(auto &z : pri){
		long long a;
		int b, c;
		tie(a, b, c) = z;
		if(b == 0){
			for(int i = 0; i < m; i++)
				if(dsu.find(f(c, i)) != dsu.find(f(c, i + 1))){
					res += a;
					dsu.unite(f(c, i), f(c, i + 1));
				}
		}else{
			for(int i = 0; i < n; i++)
				if(dsu.find(f(i, c)) != dsu.find(f(i + 1, c))){
					res += a;
					dsu.unite(f(i, c), f(i + 1, c));
				}
		}
	}
	cout << res << "\n";
	return 0;
}