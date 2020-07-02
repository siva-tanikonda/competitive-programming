#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

const int mod = 1e9 + 7;
int n, m, k;
long long s[5001], c[5001], dp[5001], ops[5001];

long long modpow(long long a, long long b){
	if(!b) return 1;
	long long ret = modpow(a, b / 2);
	ret = (ret * ret) % mod;
	if(b % 2) ret = (ret * a) % mod;
	return ret;
}

int main(){
	IO("poetry.in", "poetry.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	map<int, vector<int>> cls;
	for(int i = 1; i <= n; i++){
		cin >> s[i] >> c[i];
		cls[c[i]].push_back(s[i]);
	}
	map<char, int> form;
	for(int i = 0; i < m; i++){
		char typ;
		cin >> typ;
		form[typ]++;
	}
	dp[0] = 1;
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= n; j++)
			if(i >= s[j]) dp[i] = (dp[i] + dp[i - s[j]]) % mod;
	for(int i = 1; i <= n; i++)
		for(int j : cls[i]) ops[i] = (ops[i] + dp[k - j]) % mod;
	long long ans = 1;
	for(auto &i : form){
		long long add = 0;
		for(int j = 1; j <= n; j++)
			add = (add + modpow(ops[j], i.second)) % mod; 
		ans = (ans * add) % mod;
	}
	cout << ans << "\n";
	return 0;
}
