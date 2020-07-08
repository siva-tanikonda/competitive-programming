/*
ID: siva.ja1
TASK: fact4
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n;

int main(){
	IO("fact4.in", "fact4.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int ans = 1, five = 0, two = 0;
	for(int i = 2; i <= n; i++){
		int cur = i;
		while(cur % 5 == 0)
			cur /= 5, five++;
		while(cur % 2 == 0)
			cur /= 2, two++;
		string nxt = to_string(cur * ans);
		for(int j = (int)nxt.length() - 1; j >= 0; j--)
			if(nxt[j] != '0'){
				ans = nxt[j] - '0';
				break;
			}
	}
	if(five > two){
		for(int i = 0; i < five - two; i++){
			string nxt = to_string(5 * ans);
			for(int j = (int)nxt.length() - 1; j >= 0; j--)
				if(nxt[j] != '0'){
					ans = nxt[j] - '0';
					break;
				}
		}
	}else{
		for(int i = 0; i < two - five; i++){
			string nxt = to_string(2 * ans);
			for(int j = (int)nxt.length() - 1; j >= 0; j--)
				if(nxt[j] != '0'){
					ans = nxt[j] - '0';
					break;
				}
		}
	}
	cout << ans << "\n";
	return 0;
}
