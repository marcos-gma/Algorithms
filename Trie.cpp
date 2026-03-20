#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

const int ALPHA = 26;

struct Node{
    int nxt[ALPHA] {};
    int subtree_cnt = 0;
};

struct Trie{
    vector<Node> tr;

    Trie() : tr(1) {};
};

void add_word(Trie &trie, const string &word) {
    int node = 0;
    trie.tr[node].subtree_cnt++;

    for (char c : word) {
        int &nxt = trie.tr[node].nxt[c - 'a'];
        if (nxt == 0) {
            int len = (int)trie.tr.size();
            trie.tr[node].nxt[c - 'a'] = len;
            trie.tr.emplace_back();
        }
        node = trie.tr[node].nxt[c - 'a'];
        trie.tr[node].subtree_cnt++;
    }
}

int query(Trie &trie, const string &word) {
    int node = 0;

    for (char c : word) {
        int &nxt = trie.tr[node].nxt[c - 'a'];
        if (nxt == 0) {
            return 0;
        }
        node = trie.tr[node].nxt[c - 'a'];
    }

    return trie.tr[node].subtree_cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int words, queries;

    cin >> words >> queries;

    vector<string> todo(words);

    Trie trie;

    string word;

    for (int i = 0; i < words; i++) {

        cin >> word;

        todo[i] = word;

        add_word(trie, word);

    }

    while(queries--){
        cin >> word;

        cout << query(trie, word) << endl;
    }



    return 0;
}
