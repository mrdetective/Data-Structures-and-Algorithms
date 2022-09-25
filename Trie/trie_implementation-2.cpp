#include <bits/stdc++.h>
using namespace std;

struct trie {
  struct trie *a[26];
  bool flag = false;
  int countpref = 0;
  int count = 0;
};
struct trie *getnode() {
  struct trie *node = new trie;
  node->flag = false;

  for (int i = 0; i < 26; i++) {
    node->a[i] = NULL;
  }
  return node;
}
void insert(string s, struct trie *root) {
  int n = s.size();
  struct trie *traverse = root;
  for (int i = 0; i < n; i++) {
    int index = s[i] - 'a';
    if (traverse->a[index] == NULL) {
      traverse->a[index] = getnode();
    }
    traverse->countpref++;
    traverse = traverse->a[index];
  }
  traverse->count++;
  traverse->countpref++;
  traverse->flag = true;
}
int countwordequalto(string s, struct trie *root) {
  int n = s.size();
  struct trie *traverse = root;
  for (int i = 0; i < n; i++) {
    int ind = s[i] - 'a';
    if (traverse->a[ind] == NULL) {
      return 0;
    }
    traverse = traverse->a[ind];
  }
  return traverse->count;
}
int countstartwith(string s, struct trie *root) {
  int n = s.size();
  struct trie *traverse = root;
  for (int i = 0; i < n; i++) {
    int ind = s[i] - 'a';
    if (traverse->a[ind] == NULL) {
      return 0;
    }
    traverse = traverse->a[ind];
  }
  return traverse->countpref;
}
int main() {
  int n, m, o;
  cin >> n >> m >> o;
  struct trie *root = getnode();
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    insert(s, root);
  }
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    cout << countwordequalto(s, root) << endl;
  }
  for (int i = 0; i < o; i++) {
    string s;
    cin >> s;
    cout << countstartwith(s, root) << endl;
  }
  return 0;
}