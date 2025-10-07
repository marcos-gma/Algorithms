#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

vector<ll> rep;
vector<ll> sizes;

ll find(ll x) {
    if (x == rep[x]) {
        return x;
    }
    return rep[x] = find(rep[x]);
}

void join(ll x, ll y) {
    x = find(x);
    y = find(y);

    if (x != y) {
        if (sizes[x] < sizes[y]) {
            swap(x, y);
        }
        rep[y] = x;
        sizes[x] += sizes[y]; 
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases;
    cin >> cases;

    while (cases--) {
        ll n;
        cin >> n;

        rep.assign(n + 1, 0);
        sizes.assign(n + 1, 1);
        vector<ll> p(n + 1);
        vector<ll> d(n + 1);

        for (ll i = 1; i <= n; i++) {
            rep[i] = i;
        }

        for (ll i = 1; i <= n; i++) {
            cin >> p[i];
            join(i, p[i]); 
        }

        for (ll i = 1; i <= n; i++) {
            cin >> d[i];
        }

        ll prev_val = -1;

        for (ll i = 1; i <= n; i++) {
            ll current_val = p[d[i]];
            
            if (i > 1) {
                join(prev_val, current_val);
            }
            
            cout << sizes[find(current_val)] << " ";
            
            prev_val = current_val;
        }

        cout << endl;
    }

    return 0;
}
