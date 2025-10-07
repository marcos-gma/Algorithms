#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

vector<ll> rep;

ll find(ll x){
    if(x == rep[x]){
        return x;
    }
    return rep[x] = find(rep[x]);
}

void join(ll x, ll y){
    x = find(x);
    y = find(y);
    rep[x] = y;
}

// Adicionar ranking ou size

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n,m;
	
	vector<pair<ll,pair<ll,ll>>> adj;
	
    cin >> n >> m;
    
    rep.assign(n,0);
    
    ll a,b,c;

    for (ll i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj.push_back({c,{a - 1,b - 1}});
    }
    
    bool possible = true;
    
    ll total = 0;
    
    sort(adj.begin(),adj.end());
    
    for(ll i=0; i < n; i++){
        rep[i] = i;
    }
    
    ll edges = 0;

    for(auto [c,v] : adj){
        ll a = v.first;
        ll b = v.second;
        if(find(a) != find(b)){
            join(a,b);
            total += c;
            edges++;
        }
    }
    
    if(edges >= n - 1){
        
        cout << total << endl;
        
    }else{
        cout << "IMPOSSIBLE" << endl;
    }


	return 0;
}
