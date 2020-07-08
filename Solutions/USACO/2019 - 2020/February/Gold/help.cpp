#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

const int mod = 1e9 + 7;
int n, ov[200001];
long long pos[100000];
pair<int, int> a[100000];

int main(){
	IO("help.in", "help.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	pos[0] = 1;
	for(int i = 1; i < n; i++)
		pos[i] = (2 * pos[i - 1]) % mod;
	for(int i = 0; i < n; i++)
		ov[a[i].first]++, ov[a[i].second]--;
	for(int i = 1; i <= 2 * n; i++) ov[i] += ov[i - 1];
	long long ans = 0;
	for(int i = 0; i < n; i++) ans = (ans + pos[n - 1 - ov[a[i].first - 1]]) % mod;
	cout << ans << "\n";
	return 0;
}
