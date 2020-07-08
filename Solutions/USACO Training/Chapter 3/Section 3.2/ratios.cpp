/*
ID: siva.ja1
TASK: ratios
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int x, y, z, v[3][3];

int gcd(int a, int b){
	if(!b) return a;
	else return gcd(b, a % b);
}

int main(){
	IO("ratios.in", "ratios.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y >> z;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) cin >> v[i][j];
	tuple<int, int, int, int, int> mn(INT_MAX, 0, 0, 0, 0);
	int div1 = max(1, gcd(gcd(x, y), z));
	x /= div1, y /= div1, z /= div1;
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			for(int k = 0; k < 100; k++){
				int a = v[0][0] * i + v[1][0] * j + v[2][0] * k;
				int b = v[0][1] * i + v[1][1] * j + v[2][1] * k;
				int c = v[0][2] * i + v[1][2] * j + v[2][2] * k;
				int div = max(1, gcd(gcd(a, b), c));
				if(a / div == x && b / div == y && c / div == z && div1 <= div)
					mn = min(mn, make_tuple(i + j + k, i, j, k, div - div1 + 1));
			}
	if(get<0>(mn) == INT_MAX) cout << "NONE\n";
	else{
		int a, b, c, d, e;
		tie(a, b, c, d, e) = mn;
		cout << b << " " << c << " " << d << " " << e << "\n";
	}
	return 0;
}
