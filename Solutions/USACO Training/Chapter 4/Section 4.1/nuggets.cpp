/*
ID: siva.ja1
TASK: nuggets
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, a[10];
bool dp[100001];

int main(){
	IO("nuggets.in", "nuggets.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int one = 0, odd = 0, even = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 1) one++;
		if(a[i] % 2) odd++;
		else even++;
	}
	if(one || !odd || !even){
		cout << "0\n";
		return 0;
	}
	dp[0] = true;
	for(int i = 0; i < n; i++)
		for(int j = a[i]; j <= 1e5; j++)
			dp[j] |= dp[j - a[i]];
	for(int i = 1e5; i >= 1; i--)
		if(!dp[i]){
			cout << i << "\n";
			return 0;
		}
	return 0;
}