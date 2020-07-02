#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

template<class T> struct sparse_table{
	vector<vector<T>> jmp;
	void init(vector<T> &arr){
		int n = (int)arr.size(), dpt = 32 - __builtin_clz(n);
		jmp.assign(dpt, arr);
		for(int i = 0; i < dpt - 1; i++)
			for(int j = 0; j < n; j++)
				jmp[i + 1][j] = min(jmp[i][j], jmp[i][min(n - 1, j + (1 << i))]);
	}
	T query(int a, int b){
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct lowest_common_ancestor{
	sparse_table<pair<int, int>> rmq;
	vector<int> hgt, fir;
	vector<pair<int, int>> eul;
	void init(vector<int> adj[], int n){
		hgt.resize(n + 1);
		fir.resize(n + 1);
		eul.reserve(2 * (n + 1));
		dfs(adj, 1, 1, 0);
		rmq.init(eul);
	}
	void dfs(vector<int> adj[], int vtx, int pre, int h){
		hgt[vtx] = h;
		fir[vtx] = (int)eul.size();
		eul.push_back({h, vtx});
		for(auto &i : adj[vtx])
			if(i != pre){
				dfs(adj, i, vtx, h + 1);
				eul.push_back({h, vtx});
			}
	}
	int query(int a, int b){
		a = fir[a], b = fir[b];
		if(a > b) swap(a, b);
		return rmq.query(a, b + 1).second;
	}
};

struct heavy_light_decomposition{
	int cur;
	vector<int> par, dep, hvy, hd, pos;
	void init(vector<int> adj[], int n){
		par = vector<int>(n + 1);
		dep = vector<int>(n + 1);
		hvy = vector<int>(n + 1, -1);
		hd = vector<int>(n + 1);
		pos = vector<int>(n + 1);
		cur = 0;
		dfs(1, adj);
		decompose(1, 1, adj);
	}
	int dfs(int vtx, vector<int> adj[]){
		int sz = 1, mx_sz = 0;
		for(auto &i : adj[vtx])
			if(i != par[vtx]){
				par[i] = vtx, dep[i] = dep[vtx] + 1;
				int c_sz = dfs(i, adj);
				sz += c_sz;
				if(c_sz > mx_sz) mx_sz = c_sz, hvy[vtx] = i;
			}
		return sz;
	}
	void decompose(int vtx, int hgt, vector<int> adj[]){
		hd[vtx] = hgt, pos[vtx] = cur++;
		if(hvy[vtx] != -1) decompose(hvy[vtx], hgt, adj);
		for(auto &i : adj[vtx])
			if(i != par[vtx] && i != hvy[vtx]) decompose(i, i, adj);
	}
};

template<class T> struct segment_tree{
	vector<T> arr;
	int n;
	void init(int _n){
		n = _n, arr = vector<T>(_n * 4);
	}
	void init(vector<T> &a){
		n = (int)a.size(), arr = vector<T>((int)a.size() * 4);
		build(arr, 1, 0, (int)a.size() - 1);
	}
	void build(vector<T> &a, int vtx, int tl, int tr){
		if(tl == tr) arr[vtx] = a[tl];
		else{
			int mid = (tl + tr) / 2;
			build(a, vtx * 2, tl, mid);
			build(a, vtx * 2 + 1, mid + 1, tr);
			arr[vtx] = arr[vtx * 2] ^ arr[vtx * 2 + 1];
		}
	}
	void update(int pos, T nv){ fakeUpdate(1, 0, n - 1, pos, nv); }
	void fakeUpdate(int vtx, int tl, int tr, int pos, T nv){
		if(tl == tr) arr[vtx] = nv;
		else{
			int mid = (tl + tr) / 2;
			if(pos <= mid) fakeUpdate(vtx * 2, tl, mid, pos, nv);
			else fakeUpdate(vtx * 2 + 1, mid + 1, tr, pos, nv);
			arr[vtx] = arr[vtx * 2] ^ arr[vtx * 2 + 1];
		}
	}
	T query(int l, int r){ return fakeQuery(1, 0, n - 1, l, r); }
	T fakeQuery(int vtx, int tl, int tr, int l, int r){
		if(l > r) return 0;
		else if(l == tl && r == tr) return arr[vtx];
		else{
			int mid = (tl + tr) / 2;
			int p1 = fakeQuery(vtx * 2, tl, mid, l, min(r, mid));
			int p2 = fakeQuery(vtx * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
			return p1 ^ p2;
		}
	}
};

int n, q, x[100001];
vector<int> adj[100001];

int main(){
	IO("cowland.in", "cowland.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	lowest_common_ancestor lca;
	lca.init(adj, n);
	heavy_light_decomposition hld;
	hld.init(adj, n);
	segment_tree<int> sgt;
	sgt.init(n);
	for(int i = 1; i <= n; i++) sgt.update(hld.pos[i], x[i]);
	for(int i = 0; i < q; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1) sgt.update(hld.pos[b], c);
		else{
			int join = lca.query(b, c);
			int ans = 0, vtx1 = b;
			while(hld.hd[vtx1] != hld.hd[join]){
				ans ^= sgt.query(hld.pos[hld.hd[vtx1]], hld.pos[vtx1]);
				vtx1 = hld.par[hld.hd[vtx1]];
			}
			int vtx2 = c;
			while(hld.hd[vtx2] != hld.hd[join]){
				ans ^= sgt.query(hld.pos[hld.hd[vtx2]], hld.pos[vtx2]);
				vtx2 = hld.par[hld.hd[vtx2]];
			}
			if(hld.pos[vtx1] > hld.pos[vtx2]) swap(vtx1, vtx2);
			ans ^= sgt.query(hld.pos[vtx1], hld.pos[vtx2]);
			cout << ans << "\n";
		}
	}
	return 0;
}
