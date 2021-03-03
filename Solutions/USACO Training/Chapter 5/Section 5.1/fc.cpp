/*
ID: siva.ja1
TASK: fc
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n;
pair<double, double> a[10000];

bool cw(pair<double, double> x, pair<double, double> y, pair<double, double> z){
	double one = (y.first - x.first) * (z.second - y.second);
	double two = (y.second - x.second) * (z.first - y.first);
	return one - two > 0;
}

bool ccw(pair<double, double> x, pair<double, double> y, pair<double, double> z){
	double one = (y.first - x.first) * (z.second - y.second);
	double two = (y.second - x.second) * (z.first - y.first);
	return one - two < 0;
}

double dist(pair<double, double> x, pair<double, double> y){
	double one = (x.first - y.first) * (x.first - y.first);
	double two = (x.second - y.second) * (x.second - y.second);
	return sqrt(one + two);
}

int main(){
	IO("fc.in", "fc.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	if(n == 1){
		cout << "0\n";
		return 0;
	}
	sort(a, a + n);
	pair<double, double> p1 = a[0], p2 = a[n - 1];
	vector<pair<double, double>> u, d;
	u.push_back(p1), d.push_back(p1);
	for(int i = 1; i < n; i++){
		if(i == n - 1 || cw(p1, a[i], p2)){
			while((int)u.size() >= 2 && !cw(u[(int)u.size() - 2], u[(int)u.size() - 1], a[i]))
				u.pop_back();
			u.push_back(a[i]);
		}
		if(i == n - 1 || ccw(p1, a[i], p2)){
			while((int)d.size() >= 2 && !ccw(d[(int)d.size() - 2], d[(int)d.size() - 1], a[i]))
				d.pop_back();
			d.push_back(a[i]);
		}
	}
	vector<pair<double, double>> ord;
	for(int i = 0; i < (int)u.size() - 1; i++)
		ord.push_back(u[i]);
	for(int i = (int)d.size() - 1; i > 0; i--)
		ord.push_back(d[i]);
	double ans = dist(ord[0], ord.back());
	for(int i = 0; i < (int)ord.size() - 1; i++)
		ans += dist(ord[i], ord[i + 1]);
	cout << fixed << setprecision(2) << ans << '\n';
	return 0;
}