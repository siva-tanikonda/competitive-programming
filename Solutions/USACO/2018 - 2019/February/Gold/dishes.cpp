#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, a[100000];
stack<int> pl[100000];

bool check(int pre){
	vector<int> srt;
	stack<int> pro;
	for(int i = pre - 1; i >= 0; i--)
		pro.push(a[i]), srt.push_back(a[i]);
	sort(srt.begin(), srt.end());
	set<pair<int, int>> ins;
	for(int i = 0; i < n; i++){
		while(!pl[i].empty()) pl[i].pop();
		ins.insert(make_pair(INT_MAX, i));
	}
	int i = 0, j = 0;
	while(!pro.empty()){
		int plate = pro.top();
		pro.pop();
		int add = ins.upper_bound(make_pair(plate, -1)) -> second;
		ins.erase(ins.upper_bound(make_pair(plate, -1)));
		ins.insert(make_pair(plate, add));
		pl[add].push(plate);
		while(i < pre && !pl[j].empty() && srt[i] == pl[j].top()){
			pl[j].pop();
			ins.erase(make_pair(srt[i], j));
			if(pl[j].empty()) j++;
			else ins.insert(make_pair(pl[j].top(), j));
			i++;
		}
	}
	while(i < pre && srt[i] == pl[j].top()){
		pl[j].pop();
		ins.erase(make_pair(srt[i], j));
		if(pl[j].empty()) j++;
		else ins.insert(make_pair(pl[j].top(), j));
		i++;
	}
	return (i == pre);
}

int main(){
	IO("dishes.in", "dishes.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int l = 1, r = n;
	while(l < r){
		int mid = l + (r - l + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << "\n";
	return 0;
}
