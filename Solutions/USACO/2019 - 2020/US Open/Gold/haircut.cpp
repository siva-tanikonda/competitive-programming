#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

template<class T> struct fenwick_tree{
	vector<T> pre;
	void init(int _n, int def) { pre = vector<T>(_n + 1, def); }
	void init(vector<T> &arr){
		pre = vector<int>((int)arr.size());
		for(int i = 1; i < (int)arr.size(); i++) update(i, arr[i]);
	}
	void update(int i, T dif){
		for(; i < (int)pre.size(); i = i | (i + 1)) pre[i] += dif;
	}
	long long query(int i){
		T sum = 0;
		for(; i >= 0; i = (i & (i + 1)) - 1) sum += pre[i];
		return sum;
	}
};

int n, a[100000];
long long ans[100001];

int main(){
	IO("haircut.in", "haircut.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	fenwick_tree<int> fen;
	fen.init(n + 1, 0);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		fen.update(a[i], 1);
	}
	reverse(a, a + n);
	for(int i = 0; i < n; i++){
		ans[a[i] + 1] += fen.query(n) - fen.query(a[i]);
		fen.update(a[i], -1);
	}
	long long cnt = 0;
	for(int i = 0; i < n; i++){
		cnt += ans[i];
		cout << cnt << "\n";
	}
	return 0;
}
