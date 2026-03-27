#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<int> prefix_func(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    
    return pi;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        
        vector<int> pi = prefix_func(s);
        
        int L = n - pi[n - 1];
        
        for (int i = n; i < n + 8; i++) {
            cout << s[i % L];
        }
        cout << "..." << endl;
    }

    return 0;
}
