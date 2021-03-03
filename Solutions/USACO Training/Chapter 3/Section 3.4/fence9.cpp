/*
ID: siva.ja1
TASK: fence9
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

long double n, m, p, line[2][2];

int main(){
	IO("fence9.in", "fence9.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> p;
	if(n != 0) line[0][0] = m / n;
	if(n - p != 0) line[1][0] = m / (n - p), line[1][1] = -line[1][0] * p;
	long long cnt = 0;
	for(int i = 1; i < m; i++){
		long long l, r;
		if(line[0][0]) l = floor((i - line[0][1]) / line[0][0] + 1);
		else l = 1;
		if(line[1][0]) r = ceil((i - line[1][1]) / line[1][0] - 1);
		else r = p - 1;
		cnt += r - l + 1;
	}
	cout << cnt << "\n";
	return 0;
}