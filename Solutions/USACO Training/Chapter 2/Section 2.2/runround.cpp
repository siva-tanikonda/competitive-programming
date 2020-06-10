/*
ID: siva.ja1
TASK: runround
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
const double pi = 3.14159265358979;

long long m, mn, vis;
string str;

void recurse(int k){
	if(k < 9){
		for(int i = 1; i <= 9; i++)
			if((vis & (1 << i)) == 0){
				vis |= (1 << i), str += i + '0';
				recurse(k + 1);
				vis &= ~(1 << i), str.pop_back();
			}
	}
	if(k != 0){
		int cov = 0, cur = (str[0] - '0') % k;
		while(true){
			if(cov & (1 << cur)) break;
			cov |= (1 << cur), cur = (str[cur] - '0' + cur) % k;
		}
		if(cov == ((1 << k) - 1))
			if(stoll(str) > m && (mn == 0 || mn - m > stoll(str) - m)) mn = stoll(str);
	}
}

int main(){
	IO("runround.in", "runround.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m;
	recurse(0);
	cout << mn << "\n";
	return 0;
}