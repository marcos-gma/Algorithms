#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

const int MOD = 1e9 + 7;
const int BASE = 31;

ll compute_hash(ll val) {
    ll res = 1;
    ll b = BASE;
    ll exp = val;
    
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * b) % MOD;
        b = (b * b) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<ll> pref_A(n + 1, 0);
    vector<ll> pref_B(n + 1, 0);

    set<int> seen_A, seen_B;
    ll hash_A = 0, hash_B = 0;

    for (int i = 0; i < n; i++) {
        if (seen_A.find(a[i]) == seen_A.end()) {
            seen_A.insert(a[i]);
            hash_A = (hash_A + compute_hash(a[i])) % MOD;
        }
        pref_A[i + 1] = hash_A;
    }

    for (int i = 0; i < n; i++) {
        if (seen_B.find(b[i]) == seen_B.end()) {
            seen_B.insert(b[i]);
            hash_B = (hash_B + compute_hash(b[i])) % MOD;
        }
        pref_B[i + 1] = hash_B;
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        
        if (pref_A[x] == pref_B[y]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
