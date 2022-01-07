#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

struct fenwick_tree{
	vector<int> arr;
	void init(int n) { arr = vector<int>(n + 1, 0); }
	void update(int i, int add){
		for(; i < (int)arr.size(); i += (i & -i)) arr[i] += add;
	}
	int query(int i){
		int sum = 0;
		for(; i > 0; i -= (i & -i)) sum += arr[i];
		return sum;
	}
};

int n, p[100001];

int main(){
	IO("sleepy.in", "sleepy.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i];
	fenwick_tree fen;
	fen.init(n);
	fen.update(p[n], 1);
	int end = n;
	for(; end > 1; end--)
		if(p[end] > p[end - 1]) fen.update(p[end - 1], 1);
		else break;
	vector<int> ans;
	for(int i = 1; i < end; i++){
		ans.push_back(fen.query(p[i]) + end - i - 1);
		fen.update(p[i], 1);
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << ((i == (int)ans.size() - 1) ? '\n' : ' ');
	return 0;
}
