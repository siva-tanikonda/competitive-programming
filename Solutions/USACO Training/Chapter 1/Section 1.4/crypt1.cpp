/*
ID: siva.ja1
TASK: crypt1
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

int n, arr[9];

bool in(char c){
	for(int i = 0; i < n; i++)
		if(arr[i] == c - '0') return true;
	return false;
}

int main(){
	IO("crypt1.in", "crypt1.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int cnt = 0;
	for(int a = 0; a < n; a++)
		for(int b = 0; b < n; b++)
			for(int c = 0; c < n; c++)
				for(int d = 0; d < n; d++)
					for(int e = 0; e < n; e++){
						string x = to_string((arr[a] * 100 + arr[b] * 10 + arr[c]) * arr[d]);
						string y = to_string((arr[a] * 100 + arr[b] * 10 + arr[c]) * arr[e]);
						string z = to_string((arr[a] * 100 + arr[b] * 10 + arr[c]) * (arr[d] * 10 + arr[e]));
						bool val = ((int)x.length() == 3 && (int)y.length() == 3 && (int)z.length() == 4);
						for(auto &i : x)
							if(!in(i)) val = false;
						for(auto &i : y)
							if(!in(i)) val = false;
						for(auto &i : z)
							if(!in(i)) val = false;
						cnt += val;
					}
	cout << cnt << "\n";
	return 0;
}