/*
ID: siva.ja1
TASK: frameup
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

struct frame{
	int x1 = 30, x2 = -1, y1 = 30, y2 = -1;
};

int n, m;
string cur, gr[30];
map<char, set<char>> adj;
map<char, int> in;

bool inFrame(frame &fr, int x, int y){
	if(x == fr.x1 && y >= fr.y1 && y <= fr.y2) return true;
	else if(x == fr.x2 && y >= fr.y1 && y <= fr.y2) return true;
	else if(y == fr.y1 && x >= fr.x1 && x <= fr.x2) return true;
	else if(y == fr.y2 && x >= fr.x1 && x <= fr.x2) return true;
	else return false;
}

void generate(){
	if((int)cur.length() < (int)in.size()){
		for(auto &i : in)
			if(!i.second){
				i.second = -1;
				for(char j : adj[i.first]) in[j]--;
				cur += i.first;
				generate();
				cur.pop_back();
				for(char j : adj[i.first]) in[j]++;
				i.second = 0;
			}
	}else cout << cur << '\n';
}

int main(){
	IO("frameup.in", "frameup.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	map<char, frame> fr;
	for(int i = 0; i < n; i++){
		cin >> gr[i];
		for(int j = 0; j < m; j++){
			if(gr[i][j] == '.') continue;
			frame &abc = fr[gr[i][j]];
			abc.x1 = min(abc.x1, i);
			abc.x2 = max(abc.x2, i);
			abc.y1 = min(abc.y1, j);
			abc.y2 = max(abc.y2, j);
		}
	}
	for(auto &i : fr){
		for(int j = 0; j < n; j++)
			for(int k = 0; k < m; k++)
				if(gr[j][k] != '.' && inFrame(i.second, j, k))
					if(gr[j][k] != i.first){
						int sz = (int)adj[i.first].size();
						adj[i.first].insert(gr[j][k]);
						if(sz < (int)adj[i.first].size()) in[gr[j][k]]++;
					}
	}
	for(auto &i : fr)
		if(!in[i.first]) in[i.first] = 0;
	generate();
	return 0;
}