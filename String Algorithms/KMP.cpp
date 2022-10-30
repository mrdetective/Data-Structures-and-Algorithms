#include <bits/stdc++.h>
using namespace std;

void calclps(vector<int> &lps, string pat) {
  lps[0] = -1;
  int j = 0, i = 1;
  while (i < pat.size()) {
    if (pat[j] == pat[i]) {
      lps[i] = j;
      i++;
      j++;
    } else {
      j = 0;
      if (pat[j] == pat[i]) {
        lps[i] = j;
        j++;
        i++;
      } else {
        lps[i] = -1;
        i++;
      }
    }
  }
}
int main() {
  string s, pat;
  getline(cin, s);
  getline(cin, pat);
  vector<int> lps(pat.size());
  calclps(lps, pat);
  int j = -1, i = 0;
  vector<int> ans;
  while (i < s.size()) {
    if (pat[j + 1] == s[i]) {
      j++;
      if (j == pat.size() - 1) {
        ans.push_back(i - pat.size() + 1);
        j = lps[j];
      }
      i++;
    } else {
      if (j != -1) {
        j = lps[j];
      } else {
        i++;
      }
    }
  }
  for (auto it : ans) cout << it << " ";
  return 0;
}