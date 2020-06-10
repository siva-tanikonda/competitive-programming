#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n;
double x[50000];

bool check(double rad){
	int l = 0, r = 2e9;
	while(l < r){
		int mid = l + (r - l) / 2;
		bool val1 = true, val2 = true;
		double origin = mid / 2.0;
		int cent = 0;
		while(cent < n && x[cent] < origin) cent++;
		cent--;
		double cur = origin - rad, crad = rad;
		for(int i = cent; i >= 0; i--)
			if(x[i] < cur) val1 = false;
			else if(i > 0 && x[i - 1] < cur) cur = x[i] - (--crad);
		cur = origin + rad, crad = rad;
		for(int i = cent + 1; i < n; i++)
			if(x[i] > cur) val2 = false;
			else if(i < n - 1 && x[i + 1] > cur) cur = x[i] + (--crad);
		if(!val1 && !val2) return false;
		else if(!val1) r = mid - 1;
		else if(!val2) l = mid + 1;
		else return true;
	}
	return false;
}

int main(){
	IO("angry.in", "angry.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> x[i];
	sort(x, x + n);
	int l = 0, r = 2e9;
	while(l < r){
		int mid = l + (r - l) / 2;
		if(check(mid / 2.0)) r = mid;
		else l = mid + 1;
	}
	cout << fixed << setprecision(1) << r / 2.0 << "\n";
	return 0;
}