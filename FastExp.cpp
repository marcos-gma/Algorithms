#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

ll fexp(ll a, ll b, ll m) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int calculations;
    cin >> calculations;

    while (calculations--) {
        ll a, b, c;
        cin >> a >> b >> c;

        ll expMod = fexp(b, c, 1000000006);
        
        cout << fexp(a, expMod, 1000000007) << endl;
    }

    return 0;
}
