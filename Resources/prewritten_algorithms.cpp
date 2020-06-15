/*
BELLMAN-FORD ALGORITHM
Purpose: Finds the shortest path from one node to all other nodes
Time Complexity: O(NM)
Space Complexity: O(N)
*/

vector<long long> bellmanFord(int src, int n, vector<tuple<int, int, long long>> edg){
	vector<long long> dst(n + 1, INF);
	dst[src] = 0;
	for(int i = 0; i < n - 1; i++)
		for(auto &j : edg){
			int a, b;
			long long c;
			tie(a, b, c) = j;
			if(dst[a] < INF) dst[b] = min(dst[b], dst[a] + c);
		}
	return dst;
}

/*
BINARY SEARCH
Purpose: Find an element in a sorted array quickly.
Time Complexity: O(lg(N))
Space Complexity: O(1)
*/

int binarySearch(int val, int l, int r, vector<int> &arr){
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(arr[mid] > val) r = mid - 1;
		else if(arr[mid] < val) l = mid + 1;
		else return mid;
	}
	return -1;
}

/*
BREADTH-FIRST SEARCH
Purpose: To traverse a graph in a breadth-first manner
Time Complexity: O(N + M)
Space Complexity: O(N)
*/

void breadthFirstSearch(int src, vector<vector<int>> &adj){
	vector<bool> vis((int)adj.size(), false);
	queue<int> que;
	que.push(src);
	while(!que.empty()){
		int vtx = que.front();
		que.pop();
		for(auto i : adj[vtx])
			if(!vis[i]){
				vis[i] = true;
				que.push(i);
			}
	}
}

/*
CENTROID DECOMPOSITION
Purpose: To essentially be a divide-and-conquer method on a tree
Time Complexity: O(Nlg(N))
Space Complexity: O(N)
*/

struct centroid_decomposition{
	vector<bool> vis;
	vector<int> sub, par;
	vector<pair<int, int>> cen;
	void init(vector<vector<int>> &adj){
		vis = vector<bool>((int)adj.size());
		sub = vector<int>((int)adj.size());
		par = vector<int>((int)adj.size());
		cen = vector<pair<int, int>>((int)adj.size());
		generate({-1, 0}, 1, adj);
	}
	void generate(pair<int, int> cn, int vtx, vector<vector<int>> &adj){
		vis[vtx = centroid(vtx, adj)] = true;
		cen[vtx] = cn;
		int co = 0;
		for(auto &i : adj[vtx])
			if(!vis[i]) generate({vtx, co++}, i, adj);
	}
	int centroid(int vtx, vector<vector<int>> &adj){
		par[vtx] = -1, dfs(vtx, adj);
		for(int i = sub[vtx];;){
			pair<int, int> mx = {0, 0};
			for(auto &j : adj[vtx])
				if(!vis[j] && j != par[vtx]) mx = max(mx, {sub[j], j});
			if(mx.first * 2 <= i) return vtx;
			else vtx = mx.second;
		}
	}
	void dfs(int vtx, vector<vector<int>> &adj){
		sub[vtx] = 1;
		for(auto &i : adj[vtx])
			if(!vis[i] && i != par[vtx]){
				par[i] = vtx, dfs(i, adj);
				sub[vtx] += sub[i];
			}
	}
};

/*
DEPTH-FIRST SEARCH
Purpose: To traverse a graph in a depth-first manner
Time Complexity: O(N + M)
Space Complexity: O(N)
*/

void fakeDepthFirstSearch(int vtx, vector<bool> &vis, vector<vector<int>> &adj){
	vis[vtx] = true;
	for(auto i : adj[vtx])
		if(!vis[i]) fakeDepthFirstSearch(i, vis, adj);
}

void depthFirstSearch(int src, vector<vector<int>> &adj){
	vector<bool> vis((int)adj.size(), false);
	fakeDepthFirstSearch(src, vis, adj);
}

/*
DIJKSTRA'S ALGORITHM
Purpose: To find the shortest path from one vertex to all other vertices in a graph without negative edges
Time Complexity: O(Nlg(N) + M)
*/

vector<long long> dijkstra(int src, vector<vector<pair<int, long long>>> &adj){
	vector<long long> dst((int)adj.size(), INF);
	vector<bool> vis((int)adj.size(), false);
	priority_queue<pair<long long, int>> que;
	dst[src] = 0;
	que.push({0, src});
	while(!que.empty()){
		int vtx = que.top().second;
		que.pop();
		if(vis[vtx]) continue;
		vis[vtx] = true;
		for(auto i : adj[vtx])
			if(dst[i.first] > dst[vtx] + i.second){
				dst[i.first] = dst[vtx] + i.second;
				que.push({-dst[i.first], i.first});
			}
	}
	return dst;
}

/*
EUCLID'S ALGORITHM
Purpose: Calculate the greatest-common divisor of two numbers
Time Complexity: O(lg(N))
Space Complexity: O(1)
*/

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

/*
EULERIAN PATH ALGORITHM
Purpose: To find the Eulerian path of a graph
Time Complexity: O(N + M)
Space Complexity: O(N + M)
*/

template<bool DIR> struct eulerian_path{
	vector<bool> vis;
	vector<pair<int, int>> ans;
	vector<pair<pair<int, int>, int>> ret;
	vector<vector<pair<int, int>>::iterator> its;
	vector<vector<pair<int, int>>> adj;
	void addEdge(int a, int b){
		int m = (int)vis.size();
		vis.push_back(false);
		adj[a].push_back({b, m});
		if(!DIR) adj[b].push_back({a, m});
	}
	void createSize(int n){
		adj.assign(n + 1, vector<pair<int, int>>());
		its.resize(n + 1); 
	}
	void init(){
		for(int i = 1; i < (int)adj.size(); i++) its[i] = adj[i].begin();
		vector<pair<pair<int, int>, int>> s = {{{1, -1}, -1}};
		while((int)s.size() > 0){
			int x = s.back().first.first;
			auto &it = its[x], en = adj[x].end();
			while(it != en && vis[it -> second]) it++;
			if(it == en){
				if((int)ret.size() && ret.back().first.second != x) return;
				ret.push_back(s.back()), s.pop_back();
			}else{
				s.push_back({{it -> first, x}, it -> second});
				vis[it -> second] = true;
			}
		}
		if((int)ret.size() != (int)vis.size() + 1) return;
		for(auto &i : ret) ans.push_back({i.first.first, i.second});
		reverse(ans.begin(), ans.end());
	}
};

/*
EULER'S TOTIENT FUNCTION
Purpose: Calculate the number of numbers in [1, N] that are coprime to N
Time Complexity: O(sqrt(N))
Space Complexity: O(1)
*/

int phi(int n){
	int res = n;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0){
			while(n % i == 0) n /= i;
			res -= res / i;
		}
	if(n > 1) res -= res / n;
	return res;
}

/*
EXTENDED EUCLID'S ALGORITHM
Purpose: Find the solution to a diophantine equation.
Time Complexity: O(lg(N))
Space Complexity: O(1)
*/

tuple<int, int, int> gcd(int a, int b){
	if(b == 0) return {1, 0, a};
	else{
		int x, y, g;
		tie(x, y, g) = gcd(b, a % b);
		return {y, x - (a / b) * y, g};
	}
}

/*
FACTORIALS
Purpose: To find all the factorials from 0 to N and the inverses of those factorials.
Time Complexity: [Build] O(Nlg(N)) [Query] O(1)
Space Complexity: O(N)
*/

struct factorials{
	vector<vector<long long>> arr;
	int mod;
	void init(int _n, int _mod){
		arr = vector<vector<long long>>(_n, vector<long long>(2));
		mod = _mod;
		arr[0][0] = arr[0][1] = 1;
		for(int i = 1; i <= _n; i++){
			arr[i][0] = arr[i - 1][0] * i;
			arr[i][1] = modularExponentiation(arr[i][0], mod - 2, mod);
		}
	}
	long long fac(int x){ return arr[x][0]; }
	long long fac_inv(int x){ return arr[x][1]; }
};

/*
FENWICK TREE
Purpose: Run prefix sum queries and updates quickly
Time Complexity: [Build] O(Nlg(N)), [Query] O(lg(N)), [Update] O(lg(N))
Space Complexity: O(N)
*/

template<class T> struct fenwick_tree{
	vector<T> pre;
	void init(int _n, int def) { pre = vector<T>(_n, def) }
	void init(vector<T> &arr){
		pre = vector<int>((int)arr.size());
		for(int i = 0; i < (int)arr.size(); i++) update(i, arr[i]);
	}
	void update(int pos, T dif){
		for(; pos < (int)pre.size(); pos |= pos + 1) pre[pos] += dif;
	}
	long long query(int pos){
		T sum = 0;
		for(; pos >= 0; pos = (pos & (pos + 1)) - 1) sum += pre[pos];
		return sum;
	}
};

/*
FLOYD-WARSHALL ALGORITHM
Purpose: To find the shortest paths from every node to every other node
Time Complexity: O(N^3)
Space Complexity: O(N^2)
*/

vector<vector<long long>> floydWarshall(vector<vector<long long>> &adj){
	vector<vector<long long>> dst((int)adj.size(), vector<long long>((int)adj.size(), INF));
	for(int i = 1; i < (int)adj.size(); i++)
		for(int j = 1; j < (int)adj.size(); j++)
			if(i == j) dst[i][j] = 0;
			else if(adj[i][j] != 0) dst[i][j] = adj[i][j];
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(dst[i][k] < INF && dst[k][j] < INF)
					dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
	return dst;
}

/*
GAUSSIAN ELIMINATION
Purpose: To find the solution to a system of linear equations
Time Complexity: O(N^3)
Space Complexity: O(N^2)
*/

struct gaussian_elimination{
	vector<double> ans;
	vector<int> whr;
	int init(vector<vector<double>> &mat, double acc){
		int n = (int)mat.size(), m = (int)mat[0].size();
		whr = vector<int>(m, -1);
		for(int i = 0, j = 0; i < m && j < n; i++){
			int sel = j;
			for(int k = j; k < n; k++)
				if(abs(mat[k][i]) > abs(mat[sel][i])) sel = k;
			if(abs(mat[sel][i]) < acc) continue;
			for(int k = i; k <= m; k++) swap(mat[sel][k], mat[j][k]);
			whr[i] = j;
			for(int k = 0; k < n; k++)
				if(k != j){
					double c = mat[k][i] / mat[j][i];
					for(int l = i; l <= m; l++) mat[k][l] -= mat[j][l] * c;
				}
			j++;
		}
		ans = vector<double>(m, 0);
		for(int i = 0; i < m; i++)
			if(whr[i] != -1) ans[i] = mat[whr[i]][m] / mat[whr[i]][i];
		for(int i = 0; i < n; i++){
			double sum = 0;
			for(int j = 0; j < m; j++) sum += ans[j] * mat[i][j];
			if(abs(sum - mat[i][m]) > acc) return 0;
		}
		for(int i = 0; i < m; i++)
			if(whr[i] == -1) return INF;
		return 1;
	}
};

/*
HEAVY-LIGHT DECOMPOSITION
Purpose: To divide a tree into multiple paths whose lengths do not exceed lg(N)
Time Complexity: O(N + M)
Space Complextiy: O(N)
*/

struct heavy_light_decomposition{
	int n, cur;
	vector<int> par, dep, hvy, hd, pos;
	void init(vector<vector<int>> &adj){
		par = vector<int>((int)adj.size());
		dep = vector<int>((int)adj.size());
		hvy = vector<int>((int)adj.size(), -1);
		hd = vector<int>((int)adj.size());
		pos = vector<int>((int)adj.size());
		cur = 1;
		dfs(1, adj);
		decompose(1, 1, adj);
	}
	int dfs(int vtx, vector<vector<int>> &adj){
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
	void decompose(int vtx, int hgt, vector<vector<int>> &adj){
		hd[vtx] = hgt, pos[vtx] = cur++;
		if(hvy[vtx] != -1) decompose(hvy[vtx], hgt, adj);
		for(auto &i : adj[vtx])
			if(i != par[vtx] && i != hvy[vtx]) decompose(i, i, adj);
	}
};

/*
KOSARAJU'S ALGORITHM
Purpose: To find the strongly-connected components of a graph
Time Complexity: O(N + M)
Space Complexity: O(N)
*/

struct kosaraju{
	vector<vector<int>> rad, res;
	vector<bool> vis;
	vector<int> ord, comp;
	void init(vector<vector<int>> &adj){
		for(int i = 1; i < (int)adj.size(); i++)
			for(auto &j : adj[i]) rad[j].push_back(i);
		vis.assign((int)adj.size(), false);
		for(int i = 1; i < (int)adj.size(); i++)
			if(!vis[i]) dfs1(i, adj);
		vis.assign(n, false);
		for(int i = 1; i < (int)adj.size(); i++){
			int vtx = ord[(int)adj.size() - 1 - i];
			if(!vis[vtx]){
				dfs2(vtx);
				res.push_back({});
				for(auto &j : comp) res[(int)res.size() - 1].push_back(j);
				comp.clear();
			}
		}
	}
	void dfs1(int vtx, vector<vector<int>> &adj){
		vis[vtx] = true;
		for(auto &i : adj[vtx])
			if(!vis[i]) dfs1(i);
		ord.push_back(vtx);
	}
	void dfs2(int vtx){
		vis[vtx] = true;
		comp.push_back(vtx);
		for(auto &i : rad[vtx])
			if(!vis[i]) dfs2(i);
	}
};

/*
KRUSKAL'S ALGORITHM
Purpose: To find the minimum-spanning tree of a graph
Time Complexity: O(Mlg(N))
Space Complexity: O(N)
*/

vector<tuple<long long, int, int>> kruskal(int n, vector<tuple<long long, int, int>> &edg){
	sort(edg.begin(), edg.end());
	union_find un, un.init(n + 1);
	vector<tuple<long long, int, int>> res;
	for(auto &i : edg){
		long long a;
		int b, c;
		tie(a, b, c) = i;
		if(!un.same_set(b, c)){
			res.push_back(i);
			un.unite(b, c);
		}
	}
	return res;
}

/*
LOWEST-COMMON ANCESTOR
Purpose: To solve the lowest-common ancestor problem
Time Complexity: [Build]O(Nlg(N)), [Query]O(1)
Space Complexity: O(Nlg(N))
*/

struct lowest_common_ancestor{
	sparse_table<pair<int, int>> rmq;
	vector<int> hgt, fir;
	vector<pair<int, int>> eul;
	void init(vector<vector<int>> &adj){
		hgt.resize((int)adj.size());
		fir.resize((int)adj.size());
		eul.reserve(2 * (int)adj.size());
		dfs(adj, 1, 1, 0);
		rmq.init(eul);
	}
	void dfs(vector<vector<int>> &adj, int vtx, int pre, int h){
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

/*
MATRIX MULTIPLICATION
Purpose: To multiply two matrices
Time Complexity: O(N^3)
Space Complexity: O(N^2)
*/

vector<vector<long long>> matrixMultiplication(vector<vector<long long>> a, vector<vector<long long>> b, long long mod){
	if(a[0].size() != b.size()) return {};
	vector<vector<long long>> mat((int)a.size(), vector<long long>((int)b[0].size(), 0));
	for(int i = 0; i < (int)a.size(); i++)
		for(int j = 0; j < (int)b[0].size(); j++)
			for(int k = 0; k < (int)a[0].size(); k++)
				mat[i][j] = (mat[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
	return mat;
}

/*
MATRIX EXPONENTIATION
Purpose: To exponentiate a matrix quickly
Time Complexity: O((N^3)lg(M))
Space Complexity: O(N^2)
*/

vector<vector<long long>> matrixExponentiation(vector<vector<long long>> x, long long n, long long mod){
	if(n == 0){
		vector<vector<long long>> id((int)x.size(), vector<long long>((int)x.size(), 0));
		for(int i = 0; i < (int)x.size(); i++) id[i][i] = 1 % mod;
		return id;
	}
	vector<vector<long long>> val = matrixExponentiation(x, n / 2, mod);
	val = matrixMultiplication(x, x, mod);
	if(n % 2 == 1) val = matrixMultiplication(val, x, mod);
	return val;
}

/*
MODULAR EXPONENTIATION
Purpose: To quickly calculate exponents
Time Complexity: O(lg(N))
Space Complexity: O(1)
*/

long long modularExponentiation(long long x, long long n, long long mod){
	if(n == 0) return 1 % mod;
	long long val = modularExponentiation(x, n / 2, mod);
	val = (val * val) % mod;
	if(n % 2 == 1) val = (val * x) * mod;
	return val;
}

/*
INDEXED SET
Purpose: To create a set that is indexed, allowing us to make quick queries with indexed elements.
Time Complexity: [Query]O(lg(N)), [Update]O(lg(N))
Space Complexity: O(N)
*/

typedef tree<TYPE, null_type, COMPARATOR<TYPE>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/*
PRIME FACTORIZATION
Purpose: To get the prime factorization of a number
Time Complexity: O(sqrt(N))
Space Complexity: O(N)
*/

vector<int> primeFactorization(int n){
	vector<int> fac;
	for(int i = 2; i * i <= n; i++)
		while(n % i == 0)
			fac.push_back(i), n /= i;
	if(n > 1) fac.push_back(n);
	return fac;
}

/*
PRIME NUMBER CHECK
Purpose: To check if a number is prime
Time Complexity: O(sqrt(N))
Space Complexity: O(1)
*/

bool primeCheck(int n){
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0) return false;
	return true;
}

/*
PRIM'S ALGORITHM
Purpose: To find the minimum-spanning tree of a graph
Time Complexity: O(Mlg(N))
Space Complexity: O(N)
*/

void getAdjacent(int vtx, vector<vector<pair<int, long long>>> &adj, priority_queue<tuple<long long, int, int>> &que, vector<bool> &vis){
	vis[vtx] = true;
	for(auto &i : adj[vtx])
		if(!vis[i.first]) que.push({-i.second, i.first, vtx});
}

vector<tuple<int, int, long long>> prim(vector<vector<pair<int, long long>>> &adj){
	vector<bool> vis((int)adj.size());
	priority_queue<tuple<long long, int, int>> que;
	getAdjacent(1, adj, que, vis);
	vector<tuple<int, int, long long>> res;
	while(!que.empty()){
		long long c;
		int a, b;
		tie(c, b, a) = que.top();
		que.pop();
		if(!vis[b]){
			res.push_back({a, b, -c});
			getAdjacent(b, adj, que, vis);
		}
	}
	return res;
}

/*
RANDOM NUMBER GENERATOR
Purpose: To generate random numbers in a range
Time Complexity: O(N)
Space Complexity: O(1)
*/

int random_number_generator(int a, int b){
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution<int>(a, b)(rng);
}

/*
ROLLING HASH
Purpose: This function finds the hash value of a string, and this can be used to find congruent strings
Time Complexity: O(N)
Space Complexity: O(1)
*/

long long rollingHash(string str, int p, int m){
	long long ret = 0;
	long long pow = 1;
	for(auto &i : str){
		ret = (ret + (i - 'a' + 1) * pow) % m;
		pow = (pow * p) % m;
	}
	return ret;
}

/*
SEGMENT TREE
Purpose: Run range queries and point updates in an array
Time Complexity: [Build] O(N), [Query] O(lg(N)), [Update] O(lg(N))
Space Complexity: O(N)
*/

template<class T> struct segment_tree{
	vector<T> tr;
	int n;
	void init(int _n){
		n = _n, tr = vector<T>(_n * 3);
	}
	void init(vector<T> &arr){
		n = (int)arr.size(), tr = vector<T>((int)arr.size() * 3);
		build(arr, 1, 0, (int)arr.size() - 1);
	}
	void build(vector<T> &arr, int vtx, int l, int r){
		if(l == r) tr[vtx] = arr[l];
		else{
			int mid = l + (r - l) / 2;
			build(arr, vtx * 2, l, mid);
			build(arr, vtx * 2 + 1, mid + 1, r);
			tr[vtx] = tr[vtx * 2] + tr[vtx * 2 + 1];
		}
	}
	void update(int pos, T nv){ fakeUpdate(1, 0, n - 1, pos, nv); }
	void fakeUpdate(int vtx, int l, int r, int pos, T nv){
		if(l == r) tr[vtx] = nv;
		else{
			int mid = l + (r - l) / 2;
			if(l <= vtx && pos <= mid) fakeUpdate(vtx * 2, l, mid, pos, nv);
			else fakeUpdate(vtx * 2 + 1, mid + 1, r, pos, nv);
			tr[vtx] = tr[vtx * 2] + tr[vtx * 2 + 1];
		}
	}
	T query(int l, int r){ return fakeQuery(1, 0, n - 1, l, r); }
	T fakeQuery(int vtx, int s, int e, int l, int r){
		if(r < s || e < l) return 0;
		else if(l <= s && e <= r) return tr[vtx];
		else{
			int mid = s + (e - s) / 2;
			int p1 = fakeQuery(vtx * 2, s, mid, l, r);
			int p2 = fakeQuery(vtx * 2 + 1, mid + 1, e, l, r);
			return p1 + p2;
		}
	}
};

/*
SIEVE OF ERATOSTHENES
Purpose: To find whether the first N natural numbers are prime or not.
Time Complexity: O(Nlg(lg(N)))
Space Complexity: O(N)
*/

struct sieve_of_eratosthenes{
	vector<bool> prm;
	void init(int n){
		prm = vector<bool>(n + 1, true);
		prm[0] = prm[1] = false;
		for(int i = 2; i <= n; i++)
			if(prm[i] && (long long)i * i <= n)
				for(int j = i * i; j <= n; j += i) prm[j] = false;
	}
};

/*
SPARSE TABLE
Purpose: Solve range minimum queries on a static array.
Time Complexity: [Build] O(Nlg(N)), [Query] O(1)
Space Complexity: O(Nlg(N))
*/

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

/*
TARJAN'S ALGORITHM
Purpose: Find all strongly-connected components in a graph
Time Complexity: O(N + M)
Space Complexity: O(N)
*/

struct tarjan{
	vector<int> num, low;
	vector<bool> vis;
	stack<int> que;
	vector<vector<int>> res;
	int sum, cnt;
	void init(vector<vector<int>> &adj){
		num = vector<int>((int)adj.size(), -1);
		low = vector<int>((int)adj.size(), 0);
		vis = vector<bool>((int)adj.size(), false);
		sum = cnt = 0;
		for(int i = 1; i < (int)adj.size(); i++)
			if(num[i] == -1) dfs(i, adj);
	}
	void dfs(int vtx, vector<vector<int>> &adj){
		low[vtx] = num[vtx] = sum++;
		que.push(vtx);
		vis[vtx] = true;
		for(auto &i : adj[vtx]){
			if(num[i] == -1) dfs(i, adj);
			if(vis[i]) low[vtx] = min(low[vtx], low[i]);
		}
		if(low[vtx] == num[vtx]){
			res.push_back({});
			while(true){
				int nxt = que.top();
				que.pop();
				vis[nxt] = false;
				res[cnt].push_back(nxt);
				if(vtx == nxt) break;
			}
			cnt++;
		}
	}
};

/*
TERNARY SEARCH
Purpose: To find an element in a sorted array
Time Complexity: O(lg(N))
Space Complexity: O(1)
*/

int ternarySearch(int val, int l, int r, vector<int> &arr){
	while(l <= r){
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;
		if(arr[mid1] == val) return mid1;
		else if(arr[mid2] == val) return mid2;
		else if(val < arr[mid1]) r = mid1 - 1;
		else if(val > arr[mid2]) l = mid2 + 1;
		else l = mid1 + 1, r = mid2 - 1;
	}
	return -1;
}

/*
TOPOLOGICAL SORT
Purpose: Sort the vertices of a directed graph (without cycles), such that there are no back-edges in the array
Time Complexity: O(N + M)
Space Complexity: O(N)
*/

void dfs(int vtx, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &ans){
	vis[vtx] = true;
	for(auto i : adj[vtx])
		if(!vis[i]) dfs(i, vis, adj);
	ans.push_back(vtx);
}

vector<int> topologicalSort(vector<vector<int>> &adj){
	vector<bool> vis((int)adj.size(), false);
	vector<int> ans;
	for(int i = 1; i <= n; i++)
		if(!vis[i]) dfs(i, vis, adj, ans);
	reverse(ans.begin(), ans.end());
	return ans;
}

/*
UNION-FIND ALGORITHM
Purpose: A data structure that has the ability of uniting disjoint sets, and finding the sizes of these sets
Time Complexity: [Build] O(N), [Query] O(lg(N))
Space Complexity: O(N)
*/

struct union_find{
	vector<int> par;
	void init(int _n){ par = vector<int>(_n + 1, -1); }
	int size(int x){ return -par[find(x)]; }
	int find(int x){
		return par[x] < 0 ? x : par[x] = find(par[x]);
	}
	void unite(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		if(par[a] > par[b]) swap(a, b);
		par[a] += par[b], par[b] = a;
	}
};