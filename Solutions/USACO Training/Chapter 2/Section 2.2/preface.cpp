/*
ID: siva.ja1
TASK: preface
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

int n;

int main(){
	IO("preface.in", "preface.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	map<char, int> cnt;
	map<int, string> pos;
	pos[1] = "I", pos[5] = "V", pos[10] = "X", pos[50] = "L";
	pos[100] = "C", pos[500] = "D", pos[1000] = "M";
	pos[4] = "IV", pos[9] = "IX", pos[40] = "XL", pos[90] = "XC";
	pos[400] = "CD", pos[900] = "CM";
	for(int i = 1; i <= n; i++){
		int cur = i;
		while(cur > 0){
			auto it = pos.upper_bound(cur);
			it--;
			cur -= it -> first;
			for(auto &j : it -> second) cnt[j]++;
		}
	}
	string ord = "IVXLCDM";
	for(auto &i : ord)
		if(cnt[i] > 0) cout << i << " " << cnt[i] << "\n";
	return 0;
}