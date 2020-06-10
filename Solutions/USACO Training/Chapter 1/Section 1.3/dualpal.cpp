/*
ID: siva.ja1
TASK: dualpal
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

int n, s;

string changeBase(int val, int base){
	string str;
	int mx = 1;
	while(mx <= val) mx *= base;
	mx /= base;
	while(mx > 0){
		str += val / mx;
		val %= mx;
		mx /= base;
	}
	return str;
}

int main(){
	IO("dualpal.in", "dualpal.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	while(n > 0){
		s++;
		int sum = 0;
		for(int i = 2; i <= 10; i++){
			string conv = changeBase(s, i);
			bool val = true;
			for(int j = 0; j < (int)conv.length() / 2; j++)
				if(conv[j] != conv[(int)conv.length() - 1 - j]) val = false;
			sum += val;
		}
		if(sum >= 2) cout << s << "\n", n--;
	}
	return 0;
}