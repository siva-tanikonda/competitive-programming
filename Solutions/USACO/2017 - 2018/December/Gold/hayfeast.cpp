#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, a[100000][2];
long long m;

long long flavor(int lim){
	long long sum = 0, mx = 0;
	for(int i = 0; i < n; i++)
		if(a[i][1] > lim) sum = 0;
		else sum += a[i][0], mx = max(mx, sum);
	return mx;
}

int main(){
	IO("hayfeast.in", "hayfeast.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
	int l = 1, r = 1e9;
	while(l < r){
		int mid = l + (r - l) / 2;
		if(flavor(mid) >= m) r = mid;
		else l = mid + 1;
	}
	cout << r << "\n";
	return 0;
}
