/*
ID: siva.ja1
TASK: pprime
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

int a, b;

bool prime(int n){
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0) return false;
	return true;
}

void recurse(int cur, int mx, string &str, vector<int> &pal){
	if(cur == 0)
		for(char i = '1'; i <= '9'; i += 2){
			str += i;
			recurse(cur + 1, mx, str, pal);
			str.pop_back();
		}
	else if(cur < (mx + 1) / 2)
		for(char i = '0'; i <= '9'; i++){
			str += i;
			recurse(cur + 1, mx, str, pal);
			str.pop_back();
		}
	else{
		for(int i = mx / 2 - 1; i >= 0; i--) str += str[i];
		int num = stoi(str);
		if(num >= a && num <= b && prime(num)) pal.push_back(num);
		for(int i = 0; i < mx / 2; i++) str.pop_back(); 
	}
}

int main(){
	IO("pprime.in", "pprime.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	vector<int> pal;
	string str;
	for(int i = 1; i <= 8; i++) recurse(0, i, str, pal);
	sort(pal.begin(), pal.end());
	for(auto &i : pal) cout << i << "\n";
	return 0;
}