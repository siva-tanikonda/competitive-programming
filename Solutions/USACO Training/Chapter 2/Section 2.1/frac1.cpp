/*
ID: siva.ja1
TASK: frac1
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
bool inc[161][161];

bool isPrime(int num){
	if(num < 2) return false;
	for(int i = 2; i * i <= num; i++)
		if(num % i == 0) return false;
	return true;
}

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main(){
	IO("frac1.in", "frac1.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<pair<int, int>> rec;
	rec.push_back({0, 1});
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++){
			int div = gcd(i, j), num = j / div, den = i / div;
			if(!inc[num][den]) 
				inc[num][den] = true, rec.push_back({num, den});
		}
	set<tuple<long double, int, int>> ans;
	for(auto &i : rec) ans.insert({(long double)i.first / i.second, i.first, i.second});
	for(auto &i : ans) cout << get<1>(i) << "/" << get<2>(i) << "\n";
	return 0;
}