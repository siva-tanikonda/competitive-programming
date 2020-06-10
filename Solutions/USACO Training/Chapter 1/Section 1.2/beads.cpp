/*
ID: siva.ja1
TASK: beads
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n;
string str;

int main(){
	IO("beads.in", "beads.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> str;
	int mx = 0;
	for(int i = 0; i < n; i++){
		string cpy(str);
		rotate(cpy.begin(), cpy.begin() + i + 1, cpy.end());
		int sum = 0, j = 0;
		char det = ' ';
		while(j < n){
			if(det == ' ' && cpy[j] != 'w') det = cpy[j];
			if(det != ' ' && cpy[j] != 'w' && cpy[j] != det) break;
			j++, sum++;
		}
		int k = n - 1;
		det = ' ';
		while(k >= j){
			if(det == ' ' && cpy[k] != 'w') det = cpy[k];
			if(det != ' ' && cpy[k] != 'w' && cpy[k] != det) break;
			k--, sum++;
		}
		mx = max(mx, sum);
	}
	cout << mx << "\n";
	return 0;
}