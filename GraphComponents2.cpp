#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

vector<ll> rep;
vector<ll> sizes;

ll parents;

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
        parents--;
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

    ll n, m, a, b;
    
    cin >> n >> m;
    
    rep.assign(n + 1, 0);
    sizes.assign(n + 1, 1);

    for (ll i = 1; i <= n; i++) {
        rep[i] = i;
    }
    
    parents = n;
    
    ll largest = 0;
    
    for(ll i=0; i < m; i++){
        cin >> a >> b;
        
        join(a,b);
        
        largest = max(largest,max(sizes[find(a)],sizes[find(b)]));
        

        cout << parents << " " << largest << endl;
        
    }
    
 
    return 0;
}
