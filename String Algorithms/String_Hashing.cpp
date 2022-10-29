#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int p = 31, m = 1e9 + 9;
  long long hash_value = 0;
  long long p_pow = 1;
  for (char c : s) {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  cout << hash_value << endl;
  return 0;
}