#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n, arr[100000], lft[100000], rgt[100000];

int main(){
	IO("bphoto.in", "bphoto.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	indexed_set ist;
	for(int i = 0; i < n; i++){
		lft[i] = ist.order_of_key(arr[i]);
		ist.insert(arr[i]);
	}
	ist.clear();
	for(int i = n - 1; i > -1; i--){
		rgt[i] = ist.order_of_key(arr[i]);
		ist.insert(arr[i]);
	}
	long long cnt = 0;
	for(int i = 0; i < n; i++)
		if(max(lft[i], rgt[i]) > 2 * min(lft[i], rgt[i])) cnt++;
	cout << cnt << "\n";
	return 0;
}