#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

const int mod = 1e9 + 7, pol = 31;
int n, m;
string gen[1000];

bool check(int len){
	vector<long long> hsh(1000, 0);
	set<long long> cov;
	long long p = 1;
	bool val = true;
	for(int i = 0; i < len; i++){
		for(int j = 0; j < 2 * n; j++){
			hsh[j] = (hsh[j] + (gen[j][i] - 'a' + 1) * p) % mod;
			if(i == len - 1){
				if(j < n) cov.insert(hsh[j]);
				else if(cov.find(hsh[j]) != cov.end()) val = false; 
			}
		}
		p = (p * pol) % mod;
	}
	if(val) return true;
	long long pp = 1;
	for(int i = len; i < m; i++){
		cov.clear();
		val = true;
		for(int j = 0; j < n * 2; j++){
			hsh[j] = (hsh[j] + (gen[j][i] - 'a' + 1) * p) % mod;
			hsh[j] = ((hsh[j] - (gen[j][i - len]) * pp) % mod + mod) % mod;
			if(j < n) cov.insert(hsh[j]);
			else if(cov.find(hsh[j]) != cov.end()) val = false;
		}
		if(val) return true;
		p = (p * pol) % mod;
		pp = (pp * pol) % mod;
	} 
	return false;
}

int main(){
	IO("cownomics.in", "cownomics.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < 2 * n; i++) cin >> gen[i];
	int l = 1, r = m;
	while(l < r){
		int mid = l + (r - l) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << r << "\n";
	return 0;
}
