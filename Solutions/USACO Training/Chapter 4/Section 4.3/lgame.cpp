/*
ID: siva.ja1
TASK: lgame
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int val[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
string str;
map<string, vector<string>> dict;
vector<pair<string, string>> ans;
set<string> pre;

int recurse1(int idx, string cur){
	if(idx < (int)str.length())
		return max(recurse1(idx + 1, cur), recurse1(idx + 1, cur + str[idx]));
	else{
		int sum = 0;
		for(char i : cur) sum += val[i - 'a'];
		for(auto &i : dict){
			string rem;
			int k = 0;
			bool work = true;
			for(int j = 0; j < (int)i.first.length(); j++){
				while(k < (int)cur.length() && cur[k] < i.first[j]) rem += cur[k++];
				if(cur[k] == i.first[j]) k++;
				else work = false;
			}
			if(!work) continue;
			while(k < (int)cur.length()) rem += cur[k++];
			if(rem.empty() || dict.find(rem) != dict.end())
				return sum;
		}
		return 0;
	}
}

void recurse2(int idx, string cur, int mx){
	if(idx < (int)str.length()){
		recurse2(idx + 1, cur, mx);
		recurse2(idx + 1, cur + str[idx], mx);
	}else if(pre.find(cur) == pre.end()){
		int sum = 0;
		for(char i : cur) sum += val[i - 'a'];
		if(sum < mx || (int)cur.size() < 3) return;
		for(auto &i : dict[cur]) ans.push_back({i, ""});
		if((int)cur.length() > 5){
			set<string> cov;
			for(int i = 0; i < (int)cur.length(); i++)
				for(int j = i + 1; j < (int)cur.length(); j++)
					for(int k = j + 1; k < (int)cur.length(); k++){
						string st;
						st += cur[i], st += cur[j], st += cur[k];
						string rem;
						for(int l = 0; l < (int)cur.length(); l++)
							if(l != i && l != j && l != k) rem += cur[l];
						if(cov.find(st) == cov.end() && cov.find(rem) == cov.end()){
							if(str == rem){
								for(int l = 0; l < (int)dict[st].size(); l++)
									for(int m = l + 1; m < (int)dict[st].size(); m++)
										ans.push_back({dict[st][l], dict[st][m]});
							}else{
								for(auto &l : dict[st])
									for(auto &m : dict[rem])
										if(l < m) ans.push_back({l, m});
										else ans.push_back({m, l});
							}
							cov.insert(str), cov.insert(rem);
						}
					}
		}
		pre.insert(cur);
	}
}

int main(){
	IO("lgame.in", "lgame.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> str;
	freopen("lgame.dict", "r", stdin);
	string s;
	while(cin >> s && s != "."){
		string srt = s;
		sort(srt.begin(), srt.end());
		dict[srt].push_back(s);
	}
	sort(str.begin(), str.end());
	for(auto &i : dict) sort(i.second.begin(), i.second.end());
	int best = recurse1(0, "");
	recurse2(0, "", best);
	cout << best << "\n";
	sort(ans.begin(), ans.end());
	for(auto &i : ans)
		if(i.second != "") cout << i.first << " " << i.second << "\n";
		else cout << i.first << "\n";
	return 0;
}