/*
ID: siva.ja1
TASK: namenum
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int cnt;
string n;
set<string> st;
map<int, vector<char>> mp;

void recurse(string str){
	if(str.length() < n.length())
		for(auto &i : mp[n[(int)str.length()] - '0']) recurse(str + i);
	else if(st.find(str) != st.end()) cnt++, cout << str << "\n";
}

int main(){
	IO("namenum.in", "namenum.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 2; i <= 9; i++)
		for(int j = 0; j < 3; j++)
			if(i > 7 || (i == 7 && j >= 1)) mp[i].push_back('A' + (i - 2) * 3 + j + 1);
			else mp[i].push_back('A' + (i - 2) * 3 + j);
	IO("dict.txt", "namenum.out");
	string wrd;
	while(cin >> wrd) st.insert(wrd);
	recurse("");
	if(cnt == 0) cout << "NONE\n";
	return 0;
}