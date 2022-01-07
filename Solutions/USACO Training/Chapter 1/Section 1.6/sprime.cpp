/*
ID: siva.ja1
TASK: sprime
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

bool prime(int num){
	if(num < 2) return false;
	for(int i = 2; i * i <= num; i++)
		if(num % i == 0) return false;
	return true;
}

void recurse(int cur, string &str, vector<int> &res){
	if(cur < n){
		for(int i = '1'; i <= '9'; i++){
			str += i;
			int num = stoi(str);
			if(prime(num)) recurse(cur + 1, str, res);
			str.pop_back();
		}
	}else{
		res.push_back(stoi(str));
	}
}

int main(){
	IO("sprime.in", "sprime.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<int> res;
	string str;
	recurse(0, str, res);
	sort(res.begin(), res.end());
	for(auto &i : res) cout << i << "\n";
	return 0;
}