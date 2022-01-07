/*
ID: siva.ja1
TASK: contact
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

struct compare{
	bool operator() (string x, string y) const {
		if(x.size() != y.size()) return x.size() < y.size();
		else return x < y;
	}
};

int a, b, n;
string str;

int main(){
	IO("contact.in", "contact.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> n;
	string add;
	while(cin >> add) str += add;
	map<string, int> freq;
	for(int i = 0; i < (int)str.length(); i++){
		string seq;
		for(int j = i; j < i + b && j < (int)str.length(); j++){
			seq += str[j];
			if((int)seq.size() >= a) freq[seq]++;
		}
	}
	map<int, set<string, compare>, greater<int>> arr;
	for(auto &i : freq) arr[i.second].insert(i.first);
	int cnt = 0;
	auto it = arr.begin();
	while(cnt < n && it != arr.end()){
		pair<int, set<string, compare>> elm = *it;
		it++;
		cout << elm.first << "\n";
		int sum = 0;
		for(auto &i : elm.second){
			if(i == *elm.second.begin()) cout << i;
			else cout << (sum ? ' ' : '\n') << i;
			sum = (sum + 1) % 6;
		}
		cout << "\n";
		cnt++;
	}
	return 0;
}
