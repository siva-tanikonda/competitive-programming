#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

struct point{
	long double x = 0, y = 0;
	bool operator<(const point &val) const{
		if(x != val.x) return x < val.x;
		else return y < val.y;
	}
};

int n;
point arr[50000], brr[50000];
deque<point> seq[4];
map<point, bool> cov;

long double cross(point a, point b, point c){
	long double one = (b.x - a.x) * (c.y - b.y);
	long double two = (b.y - a.y) * (c.x - b.x);
	return one - two;
}

pair<deque<point>, deque<point>> convexHull(int k, point a[]){
	sort(a, a + n);
	point p1 = a[0], p2 = a[n - 1];
	cov[p1] = cov[p2] = true;
	deque<point> u, d;
	u.push_back(p1), d.push_back(p1);
	for(int i = 1; i < n; i++){
		if(i == n - 1 || cross(p1, a[i], p2) < 0){
			while((int)u.size() > 1 && cross(u[(int)u.size() - 2], u.back(), a[i]) >= 0)
				cov[u.back()] = false, u.pop_back();
			cov[a[i]] = true, u.push_back(a[i]);
		}
		if(i == n - 1 || cross(p1, a[i], p2) > 0){
			while((int)d.size() > 1 && cross(d[(int)d.size() - 2], d.back(), a[i]) <= 0)
				cov[d.back()] = false, d.pop_back();
			cov[a[i]] = true, d.push_back(a[i]);
		}
	}
	if(u[0].x == u[1].x) u.pop_front();
	if(d.back().x == d[(int)d.size() - 2].x) d.pop_back();
	return {u, d};
}

int binarySearch(int idx, point val){
	int l = 0, r = (int)seq[idx].size() - 1;
	while(l < r){
		int mid = l + (r - l + 1) / 2;
		if(seq[idx][mid].x < val.x) l = mid;
		else r = mid - 1;
	}
	return l;
}

int main(){
	IO("curling.in", "curling.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;
	for(int i = 0; i < n; i++)
		cin >> brr[i].x >> brr[i].y;
	pair<deque<point>, deque<point>> h1 = convexHull(0, arr);
	pair<deque<point>, deque<point>> h2 = convexHull(1, brr);
	seq[0] = h1.first, seq[1] = h1.second;
	seq[2] = h2.first, seq[3] = h2.second;
	int ans[2] = {0, 0};
	for(int i = 0; i < n; i++){
		int up = binarySearch(2, arr[i]);
		int dn = binarySearch(3, arr[i]);
		if(up == (int)seq[2].size() - 1 && seq[2][up].y > seq[3][dn].y){
			ans[1] += (arr[i].y <= seq[2][up].y && arr[i].y >= seq[3][dn].y);
			continue;
		} 
		if(up == (int)seq[2].size() - 1) continue;
		long double a = (seq[2][up + 1].y - seq[2][up].y) / (seq[2][up + 1].x - seq[2][up].x);
		long double b = (seq[3][dn + 1].y - seq[3][dn].y) / (seq[3][dn + 1].x - seq[3][dn].x);
		long double ya = seq[2][up].y + (arr[i].x - seq[2][up].x) * a;
		long double yb = seq[3][dn].y + (arr[i].x - seq[3][dn].x) * b;
		ans[1] += (arr[i].y <= ya && arr[i].y >= yb);
	}
	for(int i = 0; i < n; i++){
		int up = binarySearch(0, brr[i]);
		int dn = binarySearch(1, brr[i]);
		if(up == (int)seq[0].size() - 1 && seq[0][up].y > seq[1][dn].y){
			ans[0] += (brr[i].y <= seq[0][up].y && brr[i].y >= seq[1][dn].y);
			continue;
		} 
		if(up == (int)seq[0].size() - 1) continue;
		long double a = (seq[0][up + 1].y - seq[0][up].y) / (seq[0][up + 1].x - seq[0][up].x);
		long double b = (seq[1][dn + 1].y - seq[1][dn].y) / (seq[1][dn + 1].x - seq[1][dn].x);
		long double ya = seq[0][up].y + (brr[i].x - seq[0][up].x) * a;
		long double yb = seq[1][dn].y + (brr[i].x - seq[1][dn].x) * b;
		ans[0] += (brr[i].y <= ya && brr[i].y >= yb);
	}
	cout << ans[0] << ' ' << ans[1] << '\n';
	return 0;
}