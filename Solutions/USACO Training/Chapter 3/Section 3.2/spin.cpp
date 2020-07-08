/*
ID: siva.ja1
TASK: spin
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

pair<int, vector<pair<int, int>>> w[5];
int cov[360];

int main(){
	IO("spin.in", "spin.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < 5; i++){
		int len;
		cin >> w[i].first >> len;
		for(int j = 0; j < len; j++){
			int a, b;
			cin >> a >> b;
			w[i].second.push_back({a, b});
		}
	}
	int time = -1;
	while(time < 360){
		time++;
		fill(cov, cov + 360, 0);
		for(int i = 0; i < 5; i++)
			for(auto &j : w[i].second){
				if(time) j.first = (j.first + w[i].first) % 360;
				for(int k = j.first; k <= j.first + j.second; k++)
					cov[k % 360]++;
			}
		for(int i = 0; i < 360; i++)
			if(cov[i] == 5){
				cout << time << "\n";
				return 0;
			}
	}
	cout << "none\n";
	return 0;
}
