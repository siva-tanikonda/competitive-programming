/*
ID: siva.ja1
TASK: range
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, pre[251][251];
string a[251];

int main(){
	IO("range.in", "range.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = 'x' + a[i];
	}
	map<int, int> sz;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			int add = a[i][j] - '1';
			pre[i][j] = add + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				if(i + k <= n && j + k <= n){
					int cnt = pre[i + k][j + k] - pre[i + k][j - 1] - pre[i - 1][j + k] + pre[i - 1][j - 1];
					if(!cnt) sz[k + 1]++;
				}
	for(auto &i : sz)
		cout << i.first << " " << i.second << "\n";
	return 0;
}