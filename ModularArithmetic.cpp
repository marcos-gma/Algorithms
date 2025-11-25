#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

ll mod = 1000000007;

ll toMod(string s, ll m = mod) {
    ll res = 0;
    for (char c : s) {
        res = (res * 10 + (c - '0')) % m;
    }
    return res;
}

ll fexp(ll a, ll b) {
    ll ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}


ll invMod(ll n) {
    return fexp(n, mod - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string x,y;
    
    char op;
    
    cin >> x; cin >> op; cin >> y;
    
    ll a,b;
    
    if(op == '^'){
        a = toMod(x);
        b = toMod(y, mod - 1);
        ll ans = fexp(a,b) % mod;
        cout << ans << endl;
        
        return 0;
    }
    
    a = toMod(x);
    b = toMod(y);
    
    if(op == '+'){
        ll ans = (a + b) % mod;
        cout << ans << endl;
    }
    
    if(op == '-'){
        ll ans = (a - b + mod) % mod;
        cout << ans << endl;
    }
    
    if(op == '*'){
        ll ans = (a * b) % mod;
        cout << ans << endl;
    }
    
    if (op == '/') {

        ll invB = invMod(b);
        
        cout << (a * invB) % mod << endl;
    }
    return 0;
}
