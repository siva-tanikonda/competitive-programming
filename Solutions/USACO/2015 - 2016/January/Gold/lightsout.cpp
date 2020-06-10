#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n;
pair<int, int> arr[200];

int req[201];
int main(){
	IO("lightsout.in", "lightsout.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
	vector<int> str(1, 0);
	for(int i = 0; i < n; i++){
		int a = (i + 1) % n, b = (i + 2) % n;
		str.push_back(abs(arr[i].first - arr[a].first) + abs(arr[i].second - arr[a].second));
		int dot1 = (arr[i].first - arr[a].first) * (arr[b].second - arr[a].second);
		int dot2 = (arr[b].first - arr[a].first) * (arr[i].second - arr[a].second);
		if(dot1 - dot2 > 0) str.push_back(-1);
		else str.push_back(-2);
	}
	str.back() = 0;
	for(int i = 0; i < n; i++) req[i + 1] = req[i] + str[2 * i + 1];
	req[n] = 0;
	for(int i = n - 1; i >= 0; i--) req[i] = min(req[i], req[i + 1] + str[2 * i + 1]);
	multiset<vector<int>> st;
	for(int i = 0; i < (int)str.size(); i += 2)
		for(int j = 1; i + j <= (int)str.size(); j += 2)
			st.insert(vector<int>(str.begin() + i, str.begin() + i + j));
	int res = 0;
	for(int i = 2; i + 2 < (int)str.size(); i += 2){
		int j, cost = 0;
		for(j = 1; ; j += 2){
			if(st.count(vector<int>(str.begin() + i, str.begin() + i + j)) == 1) break;
			cost += str[i + j];
		}
		res = max(res, cost + req[(i + j) / 2] - req[i / 2]);
	}
	cout << res << "\n";
	return 0;
}