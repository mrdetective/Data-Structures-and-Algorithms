#include <bits/stdc++.h>
using namespace std;

struct trie {
  struct trie *a[26];
  bool flag = false;
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
    traverse = traverse->a[index];
  }
  traverse->flag = true;
}
bool search(string s, struct trie *root) {
  int n = s.size();
  struct trie *traverse = root;
  for (int i = 0; i < n; i++) {
    int ind = s[i] - 'a';
    if (traverse->a[ind] == NULL) {
      return false;
    }
    traverse = traverse->a[ind];
  }
  return traverse->flag;
}
bool startwith(string s, struct trie *root) {
  int n = s.size();
  struct trie *traverse = root;
  for (int i = 0; i < n; i++) {
    int ind = s[i] - 'a';
    if (traverse->a[ind] == NULL) {
      return false;
    }
    traverse = traverse->a[ind];
  }
  return true;
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
    if (search(s, root)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  for (int i = 0; i < o; i++) {
    string s;
    cin >> s;
    if (startwith(s, root)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
