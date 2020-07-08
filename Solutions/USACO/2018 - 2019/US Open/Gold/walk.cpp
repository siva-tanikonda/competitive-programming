#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

const long long a = 2019201913LL;
const long long b = 2019201949LL;
const long long c = 2019201997LL; 
int n, m;
bool vis[7501];
long long dst[7501];

int main(){
	IO("walk.in", "walk.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) dst[i] = LLONG_MAX;
	for(int k = 0; k < n; k++){
		int mn = 0;
		for(int i = 1; i <= n; i++)
			if(!vis[i] && (!mn || dst[mn] > dst[i]))
				mn = i;
		vis[mn] = true;
		for(int i = 1; i <= n; i++)
			if(!vis[i]) dst[i] = min(dst[i], (a * min(mn, i) + b * max(mn, i)) % c); 
	}
	sort(dst, dst + n + 1);
	cout << dst[n + 1 - m] << "\n";
	return 0;
}
