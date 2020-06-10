/*
ID: siva.ja1
TASK: palsquare
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

int b;

string convertBase(int n){
	string str;
	int mx = 1;
	while(mx <= n) mx *= b;
	mx /= b;
	while(mx > 0){
		int rem = n / mx;
		if(rem > 9) str += (rem - 10) + 'A';
		else str += rem + '0';
		n %= mx;
		mx /= b;
	}
	return str;
}

int main(){
	IO("palsquare.in", "palsquare.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> b;
	for(int i = 1; i <= 300; i++){
		string res = convertBase(i * i);
		bool val = true;
		for(int j = 0; j < (int)res.length() / 2; j++)
			if(res[j] != res[(int)res.length() - 1 - j]) val = false;
		if(val) cout << convertBase(i) << " " << res << "\n";
	}
	return 0;
}