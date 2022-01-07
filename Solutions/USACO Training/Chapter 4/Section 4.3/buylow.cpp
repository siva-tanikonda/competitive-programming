/*
ID: siva.ja1
TASK: buylow
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

struct big_integer{
	static const int base = 1e9, dig = 9;
	vector<int> arr;
	int sig;
	big_integer() : sig(1) {}
	big_integer(long long val) { *this = val; }
	big_integer(const string &str) { read(str); }
	void operator=(const big_integer &val){
		sig = val.sig;
		arr = val.arr;
	}
	void operator=(long long val){
		sig = 1;
		if(val < 0) sig = -1, val *= -1;
		for(; val; val /= base)
			arr.push_back(val % base);
	}
	big_integer operator+(const big_integer &val) const{
		if(sig == val.sig){
			big_integer res = val;
			for(int i = 0, j = 0; i < (int)max(arr.size(), val.arr.size()) || j; i++){
				if(i == (int)res.arr.size())
					res.arr.push_back(0);
				res.arr[i] += j + (i < (int)arr.size() ? arr[i] : 0);
				j = res.arr[i] >= base;
				if(j) res.arr[i] -= base;
			}
			return res;
		}
		return *this - (-val);
	}
	big_integer operator-(const big_integer &val) const{
		if(sig == val.sig){
			if(abs() >= val.abs()){
				big_integer res = *this;
				for(int i = 0, j = 0; i < (int)val.arr.size() || j; i++){
					res.arr[i] -= j + (i < (int)val.arr.size() ? val.arr[i] : 0);
					j = res.arr[i] < 0;
					if(j) res.arr[i] += base;
				}
				res.trim();
				return res;
			}
			return -(val - *this);
		}
		return *this + (-val);
	}
	void operator*=(int val){
		if(val < 0) sig *= -1, val *= -1;
		for(int i = 0, j = 0; i < (int)arr.size() || j; i++){
			if(i == (int)arr.size()) arr.push_back(0);
			long long cur = arr[i] * (long long)val + j;
			j = (int)(cur / base);
			arr[i] = (int)(cur % base);
		}
		trim();
	}
	big_integer operator*(int val) const{
		big_integer res = *this;
		res *= val;
		return res;
	}
	friend pair<big_integer, big_integer> divisionMod(const big_integer &a1, const big_integer &b1){
		int nrm = base / (b1.arr.back() + 1);
		big_integer a = a1.abs() * nrm;
		big_integer b = b1.abs() * nrm;
		big_integer q, r;
		q.arr.resize(a.arr.size());
		for(int i = (int)a.arr.size() - 1; i >= 0; i--){
			r *= base;
			r += a.arr[i];
			int s1 = r.arr.size() <= b.arr.size() ? 0 : r.arr[(int)b.arr.size()];
			int s2 = r.arr.size() <= b.arr.size() - 1 ? 0 : r.arr[(int)b.arr.size() - 1];
			int d = ((long long)base * s1 + s2) / b.arr.back();
			r -= b * d;
			while(r < 0) r += b, d--;
			q.arr[i] = d; 
		}
		q.sig = a1.sig * b1.sig;
		r.sig = a1.sig;
		q.trim();
		r.trim();
		return make_pair(q, r / nrm);
	}
	big_integer operator/(const big_integer &val) const{
		return divisionMod(*this, val).first;
	}
	big_integer operator%(const big_integer &val) const{
		return divisionMod(*this, val).second;
	}
	void operator/=(int val){
		if(val < 0) sig *= -1, val *= -1;
		for(int i = (int)arr.size() - 1, j = 0; i >= 0; i--){
			long long cur = arr[i] + j * (long long)base;
			arr[i] = (int)(cur / val);
			j = (int)(cur % val);
		}
		trim();
	}
	big_integer operator/(int val) const{
		big_integer res = *this;
		res /= val;
		return res;
	}
	int operator%(int val) const{
		if(val < 0) val *= -1;
		int m = 0;
		for(int i = (int)arr.size() - 1; i >= 0; i--)
			m = (arr[i] + m * (long long)base) % val;
		return m * sig;
	}
	void operator+=(const big_integer &val){ *this = *this + val; }
	void operator-=(const big_integer &val){ *this = *this - val; }
	void operator*=(const big_integer &val){ *this = *this * val; }
	void operator/=(const big_integer &val){ *this = *this / val; }
	bool operator<(const big_integer &val) const{
		if(sig != val.sig) return sig < val.sig;
		if(arr.size() != val.arr.size())
			return (int)arr.size() * sig < (int)val.arr.size() * val.sig;
		for(int i = (int)arr.size() - 1; i >= 0; i--)
			if(arr[i] != val.arr[i])
				return arr[i] * sig < val.arr[i] * sig;
		return false;
	}
	bool operator>(const big_integer &val) const{
		return val < *this;
	}
	bool operator<=(const big_integer &val) const{
		return !(val < *this);
	}
	bool operator>=(const big_integer &val) const{
		return !(*this < val);
	}
	bool operator==(const big_integer &val) const{
		return !(*this < val) && !(val < *this);
	}
	bool operator!=(const big_integer &val) const{
		return *this < val || val < *this;
	}
	void trim(){
		while(!arr.empty() && !arr.back()) arr.pop_back();
		if(arr.empty()) sig = 1;
	}
	bool isZero() const{
		return arr.empty() || (arr.size() == 1 && !arr[0]);
	}
	big_integer operator-() const{
		big_integer res = *this;
		res.sig *= -1;
		return res;
	}
	big_integer abs() const{
		big_integer res = *this;
		res.sig *= res.sig;
		return res;
	}
	long long longValue() const{
		long long res = 0;
		for(int i = (int)arr.size() - 1; i >= 0; i--)
			res = res * base + arr[i];
		return res * sig;
	}
	void read(const string &str){
		sig = 1;
		arr.clear();
		int pos = 0;
		while(pos < (int)str.size() && (str[pos] == '-' || str[pos] == '+')){
			if(str[pos] == '-') sig *= -1;
			pos++;
		}
		for(int i = (int)str.size() - 1; i >= pos; i -= dig){
			int x = 0;
			for(int j = max(pos, i - dig + 1); j <= i; j++)
				x = x * 10 + str[j] - '0';
			arr.push_back(x);
		}
		trim();
	}
	friend istream& operator>>(istream &stream, big_integer &val){
		string str;
		stream >> str;
		val.read(str);
		return stream;
	}
	friend ostream& operator<<(ostream &stream, const big_integer &val){
		if(val.sig == -1) stream << '-';
		stream << (val.arr.empty() ? 0 : val.arr.back());
		for(int i = (int)val.arr.size() - 2; i >= 0; i--)
			stream << setw(dig) << setfill('0') << val.arr[i];
		return stream;
	}
	static vector<int> convert_base(const vector<int> &a, int old, int nw){
		vector<long long> p(max(old, nw) + 1);
		p[0] = 1;
		for(int i = 1; i < (int)p.size(); i++)
			p[i] = p[i - 1] * 10;
		vector<int> res;
		long long cur = 0;
		int cdig = 0;
		for(int i = 0; i < (int)a.size(); i++){
			cur += a[i] * p[cdig];
			cdig += old;
			while(cdig >= nw){
				res.push_back((int)(cur % p[nw]));
				cur /= p[nw];
				cdig -= nw;
			}
		}
		res.push_back((int)cur);
		while(!res.empty() && !res.back()) res.pop_back();
		return res;
	}
	static vector<long long> karatsuba(const vector<long long> &a, const vector<long long> &b){
		int n = (int)a.size();
		vector<long long> res(2 * n);
		if(n <= 32){
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					res[i + j] += a[i] * b[j];
			return res;
		}
		int k = n >> 1;
		vector<long long> a1(a.begin(), a.begin() + k);
		vector<long long> a2(a.begin() + k, a.end());
		vector<long long> b1(b.begin(), b.begin() + k);
		vector<long long> b2(b.begin() + k, b.end());
		vector<long long> a1b1 = karatsuba(a1, b1);
		vector<long long> a2b2 = karatsuba(a2, b2);
		for(int i = 0; i < k; i++) a2[i] += a1[i];
		for(int i = 0; i < k; i++) b2[i] += b1[i];
		vector<long long> r = karatsuba(a2, b2);
		for(int i = 0; i < (int)a1b1.size(); i++) r[i] -= a1b1[i];
		for(int i = 0; i < (int)a2b2.size(); i++) r[i] -= a2b2[i];
		for(int i = 0; i < (int)r.size(); i++) res[i + k] += r[i];
		for(int i = 0; i < (int)a1b1.size(); i++) res[i] += a1b1[i];
		for(int i = 0; i < (int)a2b2.size(); i++) res[i + n] += a2b2[i];
		return res;
	}
	big_integer operator*(const big_integer &val) const{
		vector<int> a6 = convert_base(this -> arr, dig, 6);
		vector<int> b6 = convert_base(val.arr, dig, 6);
		vector<long long> a(a6.begin(), a6.end());
		vector<long long> b(b6.begin(), b6.end());
		while(a.size() < b.size()) a.push_back(0);
		while((int)a.size() & ((int)a.size() - 1))
			a.push_back(0), b.push_back(0);
		vector<long long> c = karatsuba(a, b);
		big_integer res;
		res.sig = sig * val.sig;
		for(int i = 0, j = 0; i < (int)c.size(); i++){
			long long cur = c[i] + j;
			res.arr.push_back((int)(cur % 1000000));
			j = (int)(cur / 1000000);
		}
		res.arr = convert_base(res.arr, 6, dig);
		res.trim();
		return res;
	}
};

int n, a[5001];
pair<int, big_integer> dp[5001];

int main(){
	IO("buylow.in", "buylow.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	pair<int, big_integer> ans;
	for(int i = 1; i <= n; i++){
		dp[i].first = 1;
		for(int j = 1; j < i; j++)
			if(a[j] > a[i])
				dp[i].first = max(dp[i].first, dp[j].first + 1);
		set<int> inc;
		for(int j = i - 1; j; j--)
			if(a[j] > a[i] && dp[j].first + 1 == dp[i].first && inc.find(a[j]) == inc.end()){
				dp[i].second += dp[j].second;
				inc.insert(a[j]);
			}
		if(dp[i].first == 1) dp[i].second = 1;
		ans.first = max(ans.first, dp[i].first);
	}
	set<int> inc;
	for(int i = n; i >= 1; i--)
		if(dp[i].first == ans.first && inc.find(a[i]) == inc.end()){
			inc.insert(a[i]);
			ans.second += dp[i].second;
		}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}