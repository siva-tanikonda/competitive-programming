#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, p2[50001];
set<int> p1;

int main(){
	IO("cardgame.in", "cardgame.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= 2 * n; i++) p1.insert(i);
	for(int i = 0; i < n; i++)
		cin >> p2[i], p1.erase(p2[i]);
	vector<int> p2a, p2b;
	for(int i = 0; i < n / 2; i++) p2a.push_back(p2[i]);
	for(int i = n / 2; i < n; i++) p2b.push_back(p2[i]);
	sort(p2a.begin(), p2a.end(), greater<int>());
	sort(p2b.begin(), p2b.end());
	int cnt = 0;
	for(auto &i : p2a){
		auto it = p1.end();
		it--;
		if(*it <= i) continue;
		cnt++, p1.erase(it);
	}
	for(auto &i : p2b){
		auto it = p1.begin();
		if(*it >= i) continue;
		cnt++, p1.erase(it);
	}
	cout << cnt << "\n";
	return 0;
}