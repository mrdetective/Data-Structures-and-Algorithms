#include <bits/stdc++.h>
using namespace std;

vector<int>z_function(string s){
	vector<int>z(s.size());
	for(int i = 1 , l = 0, r = 0; i < s.size(); i++){
		if(i <= r)
			z[i] = min(z[i - l], r - i + 1);
		while(i + z[i] < s.size() && s[i + z[i]] == s[z[i]]){
			z[i]++;
		}
		if(i + z[i] - 1 > r){
			r = i + z[i] - 1;
			l = i;
		}
	}
	return z;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> z = z_function(s);
  for (int i : z) cout << i << " ";
  cout << endl;
	return 0; 
}