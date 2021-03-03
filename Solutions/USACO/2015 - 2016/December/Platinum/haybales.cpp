#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

struct segment_tree{
	vector<long long> arr[2], lzy;
	int n;
	void init(int _n, long long lst[]){
		n = _n;
		arr[0].resize(4 * (n + 1));
		arr[1].resize(4 * (n + 1));
		lzy.resize(4 * (n + 1));
		build(1, 1, n, lst);
	}
	void build(int vtx, int tl, int tr, long long lst[]){
		if(tl == tr) arr[0][vtx] = arr[1][vtx] = lst[tl];
		else{
			int mid = (tl + tr) / 2;
			build(vtx * 2, tl, mid, lst);
			build(vtx * 2 + 1, mid + 1, tr, lst);
			arr[0][vtx] = min(arr[0][vtx * 2], arr[0][vtx * 2 + 1]);
			arr[1][vtx] = arr[1][vtx * 2] + arr[1][vtx * 2 + 1];
		}
	}
	void update(int l, int r, long long add){ update(1, 1, n, l, r, add); }
	void update(int vtx, int tl, int tr, int l, int r, long long add){
		if(lzy[vtx]){
			arr[0][vtx] += lzy[vtx];
			arr[1][vtx] += (tr - tl + 1) * lzy[vtx];
			if(tl != tr){
				lzy[vtx * 2] += lzy[vtx];
				lzy[vtx * 2 + 1] += lzy[vtx];
			}
			lzy[vtx] = 0;
		}
		if(tl > tr || tl > r || tr < l) return;
		if(tl >= l && tr <= r){
			arr[0][vtx] += add;
			arr[1][vtx] += (tr - tl + 1) * add;
			if(tl != tr){
				lzy[vtx * 2] += add;
				lzy[vtx * 2 + 1] += add;
			}
		}else{
			int mid = (tl + tr) / 2;
			update(vtx * 2, tl, mid, l, r, add);
			update(vtx * 2 + 1, mid + 1, tr, l, r, add);
			arr[0][vtx] = min(arr[0][vtx * 2], arr[0][vtx * 2 + 1]);
			arr[1][vtx] = arr[1][vtx * 2] + arr[1][vtx * 2 + 1];
		}
	}
	pair<long long, long long> query(int l, int r){ return query(1, 1, n, l, r); }
	pair<long long, long long> query(int vtx, int tl, int tr, int l, int r){
		if(tl > tr || tl > r || tr < l) return {LLONG_MAX, 0};
		if(lzy[vtx]){
			arr[0][vtx] += lzy[vtx];
			arr[1][vtx] += (tr - tl + 1) * lzy[vtx];
			if(tl != tr){
				lzy[vtx * 2] += lzy[vtx];
				lzy[vtx * 2 + 1] += lzy[vtx];
			}
			lzy[vtx] = 0;
		}
		if(tl >= l && tr <= r) return {arr[0][vtx], arr[1][vtx]};
		else{
			int mid = (tl + tr) / 2;
			pair<long long, long long> a = query(vtx * 2, tl, mid, l, r);
			pair<long long, long long> b = query(vtx * 2 + 1, mid + 1, tr, l, r);
			return {min(a.first, b.first), a.second + b.second};
		}
	}
};

int n, q;
long long arr[200001];

int main(){
	IO("haybales.in", "haybales.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	segment_tree rq;
	rq.init(n, arr);
	for(int i = 0; i < q; i++){
		char typ;
		int a, b;
		cin >> typ >> a >> b;
		if(typ == 'M') cout << rq.query(a, b).first << '\n';
		else if(typ == 'S') cout << rq.query(a, b).second << '\n';
		else{
			long long c;
			cin >> c;
			rq.update(a, b, c);
		}
	}
	return 0;
}