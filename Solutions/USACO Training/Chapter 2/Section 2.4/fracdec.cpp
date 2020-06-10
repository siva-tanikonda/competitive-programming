/*
ID: siva.ja1
TASK: fracdec
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

string n;
int m;

int main(){
	IO("fracdec.in", "fracdec.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	map<int, int> vis;
	string div = "0", seq = "";
	bool dec = false;
	int i = 0, cnt = 0, cyc = -1;
	while(true){
		int zero = 0, dzro = 0;
		while(stoi(div) < m)
			if(cnt == 0){
				if(i < (int)n.length()) div += n[i++];
				else if(!dec) seq += "0.", div += "0", dec = true;
				else seq += "0", div += "0";
			}else{
				if(i < (int)n.length()) dzro++, seq += (zero > 0) ? "0" : "", div += n[i++];
				else if(!dec) seq += string(dzro, '0'), seq += ".", div += "0", dec = true;
				else seq += (zero > 0) ? "0" : "", div += "0"; 
				zero++;
			}
		cnt++;
		if(vis.find(stoi(div)) != vis.end() && dec){
			cyc = vis[stoi(div)];
			break;
		}
		if(dec) vis[stoi(div)] = (int)seq.length();
		seq.push_back(stoi(div) / m + '0');
		div = to_string(stoi(div) % m);
		if(i == (int)n.length() && stoi(div) == 0) break;
	}
	if(cyc != -1){
		while(seq.back() == seq[cyc - 1]) seq.pop_back(), cyc--;
		seq.insert(seq.begin() + cyc, '(');
		seq += ')';
	}
	cnt = 0;
	for(auto &j : seq){
		cout << j;
		cnt++;
		if(cnt == 76) cout << "\n", cnt = 0;
	}
	if(!dec) cout << ".0";
	cout << "\n";
	return 0;
}