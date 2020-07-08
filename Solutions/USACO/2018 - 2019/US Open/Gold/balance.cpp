#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, a[200000], ones;
long long mn = LLONG_MAX;

long long count(int l, int r){
	long long sum = 0;
	int one = 0;
	for(int i = l; i <= r; i++)
		if(a[i]) one++;
		else sum += one;
	return sum;
}

void scanGame(int top, int sig){
	long long zero = count(0, n - 1);
	long long one = count(n, 2 * n - 1);
	long long dif = zero - one;
	mn = min(mn, abs(dif));
	int n1 = 0;
	int j = n;
	int dip = 0;
	long long cost = 0;
	for(int i = n - 1; i >= 0; i--)
		if(a[i] == top){
			dif -= sig * (n - 1 - i), cost += n - i - 1;
			dif += sig * (ones - n), cost++;
			dif += sig * n1, cost += n1;
			dif += sig * dip, cost += dip;
			n1++;
			if(n1 + dip > n) return;
			while(n1 + dip > j - n)
				if(a[j] == 1 - top) j++;
				else if(j == 2 * n - 1)return;
				else{
					dif += sig * (n + n1 + dip - j);
					cost += n + n1 + dip - j;
					dip++, j++;
				}
			mn = min(mn, cost + abs(dif));
		}
}

int main(){
	IO("balance.in", "balance.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < 2 * n; i++){
		cin >> a[i];
		ones += a[i]; 
	}
	scanGame(1, 1);
	scanGame(0, -1);
	cout << mn << "\n";
	return 0;
}
