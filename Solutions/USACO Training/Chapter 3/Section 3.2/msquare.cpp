/*
ID: siva.ja1
TASK: msquare
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

map<vector<int>, pair<char, vector<int>>> cov;

int main(){
	IO("msquare.in", "msquare.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> cur(8);
	for(int i = 0; i < 8; i++) cin >> cur[i];
	vector<int> beg = {1, 2, 3, 4, 5, 6, 7, 8};
	queue<vector<int>> que;
	que.push(beg);
	cov[beg] = {'0', {}};
	while(!que.empty()){
		vector<int> arr = que.front();
		que.pop();
		vector<int> cpy = arr;
		reverse(cpy.begin(), cpy.end());
		if(cov.find(cpy) == cov.end())
			cov[cpy] = {'A', arr}, que.push(cpy);
		cpy = arr;
		rotate(cpy.begin(), cpy.begin() + 3, cpy.begin() + 4);
		rotate(cpy.begin() + 4, cpy.begin() + 5, cpy.end());
		if(cov.find(cpy) == cov.end())
			cov[cpy] = {'B', arr}, que.push(cpy);
		cpy = arr;
		int one = cpy[1], two = cpy[2], three = cpy[5], four = cpy[6];
		cpy[1] = four, cpy[2] = one;
		cpy[5] = two, cpy[6] = three;
		if(cov.find(cpy) == cov.end())
			cov[cpy] = {'C', arr}, que.push(cpy);
	}
	string ans;
	while(cov[cur].first != '0'){
		pair<int, vector<int>> val = cov[cur];
		ans += val.first;
		cur = val.second;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.length() << "\n";
	for(int i = 0; i < (int)ans.length(); i += 60)
		cout << ans.substr(i, min(60, (int)ans.length() - i)) << "\n";
	if(ans.empty()) cout << "\n";
	return 0;
}