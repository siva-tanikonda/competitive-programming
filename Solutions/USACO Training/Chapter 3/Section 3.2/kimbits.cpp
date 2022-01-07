/*
ID: siva.ja1
TASK: kimbits
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, base[32];
long double k, fac[32];

int main(){
	IO("kimbits.in", "kimbits.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
	long double ones = 0;
	for(int i = n; i >= 1; i--){
		long double cnt = 0;
		for(int j = 0; j <= i - 1 && j <= m - ones; j++)
			cnt += (fac[i - 1] / fac[i - 1 - j]) / fac[j];
		if(k - cnt > 0){
			cout << "1";
			k -= cnt, ones++;
		}else cout << "0";
	}
	cout << "\n";
	return 0;
}
