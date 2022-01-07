/*
ID: siva.ja1
TASK: transform
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n;
string a[10], b[10];

int rotation(bool five){
	bool val = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			val &= (a[i][j] == b[j][n - 1 - i]);
	if(val){
		cout << (five ? 5 : 1) << "\n";
		return 0;
	}
	val = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			val &= (a[i][j] == b[n - 1 - i][n - 1 - j]);
	if(val){
		cout << (five ? 5 : 2) << "\n";
		return 0;
	}
	val = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			val &= (a[i][j] == b[n - 1 - j][i]);
	if(val){
		cout << (five ? 5 : 3) << "\n";
		return 0;
	}
	return -1;
}

void reflect(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n / 2; j++){
			char tmp = a[i][j];
			a[i][j] = a[i][n - 1 - j];
			a[i][n - 1 - j] = tmp;
		}
}

int main(){
	IO("transform.in", "transform.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	int rot = rotation(false);
	if(rot == 0) return 0;
	bool val = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			val &= (a[i][j] == b[i][n - 1 - j]);
	if(val){
		cout << "4\n";
		return 0;
	}
	reflect();
	rot = rotation(true);
	if(rot == 0) return 0;
	reflect();
	val = true;
	for(int i = 0; i < n; i++) val &= (a[i] == b[i]);
	if(val){
		cout << "6\n";
		return 0;
	}
	cout << "7\n";
	return 0;
}