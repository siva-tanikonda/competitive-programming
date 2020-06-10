/*
ID: siva.ja1
TASK: lamps
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

int n, c;

int main(){
	IO("lamps.in", "lamps.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> c;
	vector<set<int>> st(4, set<int>());
	for(int i = 0; i < 4; i++)
		st[i].insert(0), st[i].insert(1);
	int cur;
	cin >> cur;
	while(cur != -1){
		if((cur - 1) % 3 == 0) st[cur % 2 + 2].erase(0);
		else st[cur % 2].erase(0);
		cin >> cur;
	}
	cin >> cur;
	while(cur != -1){
		if((cur - 1) % 3 == 0) st[cur % 2 + 2].erase(1);
		else st[cur % 2].erase(1);
		cin >> cur;
	}
	bool find = false;
	set<string> res;
	for(auto &i : st[0])
		for(auto &j : st[1])
			for(auto &k : st[2])
				for(auto &l : st[3]){
					if((i != k && j == l) || (i == k && j != l)) continue;
					string str(n, '1');
					int cnt = 0;
					if(i == k && i == 0 && j == 0){
						for(int m = 1; m <= n; m++) str[m - 1] = '0';
						cnt = (c % 2 == 0) ? 2 : 1; 
					}else if(i == k && i == 0 && j == 1){
						for(int m = 2; m <= n; m += 2) str[m - 1] = '0';
						cnt = (c % 2 == 0) ? 2 : 1;
					}else if(i == k && j == 0 && i == 1){
						for(int m = 1; m <= n; m += 2) str[m - 1] = '0';
						cnt = (c % 2 == 0) ? 2 : 1;
					}
					if(i != k)
						for(int m = 1; m <= n; m += 3) str[m - 1] = '0';
					if(i != k && i == 1 && j == 1) cnt = (c % 2 == 0) ? 4 : 1;
					else if(i != k && i == 0 && j == 0){
						for(int m = 1; m <= n; m++) str[m - 1] = (str[m - 1] == '0') ? '1' : '0';
						cnt = (c % 2 == 0) ? 2 : 3;
					}else if(i != k && i == 0){
						for(int m = 2; m <= n; m += 2) str[m - 1] = (str[m - 1] == '0') ? '1' : '0';
						cnt = (c % 2 == 0) ? 2 : 3;
					}else if(i != k && j == 0){
						for(int m = 1; m <= n; m += 2) str[m - 1] = (str[m - 1] == '0') ? '1' : '0';
						cnt = (c % 2 == 0) ? 2 : 3;
						cnt++;
					}
					if(cnt > c) continue;
					res.insert(str);
					find = true;
				}
	for(auto &i : res) cout << i << "\n";
	if(!find) cout << "IMPOSSIBLE\n";
	return 0;
}