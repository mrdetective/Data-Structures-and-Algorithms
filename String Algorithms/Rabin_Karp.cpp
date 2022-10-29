#include<bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	getline(cin,s);
	getline(cin,t);
	/*s - Pattern
	  t - String*/
	int p = 31, m = 1e9 + 9;
	int T = t.size(), S = s.size();
	vector<long long>p_pow(max(T,S)),h(T + 1);
	p_pow[0] = 1;
	for (int i = 1; i < p_pow.size(); i++)
	{
		p_pow[i] = (p * p_pow[i - 1]) % m; 
	}
	for (int i = 0; i < T; i++)
	{
		h[i + 1] = (h[i] + (t[i] - 'A' + 1) * p_pow[i]) % m;
	}
	long long h_s = 0;
	for (int i = 0; i < S; i++)
	{
		h_s = (h_s + (s[i] - 'A' + 1) * p_pow[i]) % m;
	}
	vector<int>occurances;
	for (int i = 0; i + S - 1 < T; i++)
	{
		long long cur_h = (h[i + S] + m - h[i]) % m;
		if(cur_h == h_s * p_pow[i] % m)
			occurances.push_back(i);
	}
	for(auto it: occurances) cout << it << " ";
	cout << endl;

}	