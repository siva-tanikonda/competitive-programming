/*
ID: siva.ja1
TASK: shuttle
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n;

int main(){
	IO("shuttle.in", "shuttle.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cout << n;
	int k = 1, sig = 1, cur = n;
	for(int i = 1; i < n; i++, sig *= -1){
		for(int j = 0; j < i; j++)
			cout << ((k++) % 20 ? ' ' : '\n') << (cur += (sig * 2));
		cout << ((k++) % 20 ? ' ' : '\n') << (cur += sig);
	}
	for(int i = 0; i < n; i++)
		cout << ((k++) % 20 ? ' ' : '\n') << (cur += 2 * sig);
	sig *= -1;
	for(int i = n - 1; i > 0; i--, sig *= -1){
		cout << ((k++) % 20 ? ' ' : '\n') << (cur += sig);
		for(int j = 0; j < i; j++)
			cout << ((k++) % 20 ? ' ' : '\n') << (cur += (sig * 2));
	}
	cout << ((k++) % 20 ? ' ' : '\n') << n + 1 << '\n';
	return 0;
}