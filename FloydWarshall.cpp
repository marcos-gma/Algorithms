#include <bits/stdc++.h>
#include <limits.h>
#define endl "\n"
#define ll long long


using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    ll n, m, q;

    cin >> n >> m >> q;
    
    vector<vector<ll>> dist(n, vector<ll>(n, LLONG_MAX));

    ll a,b,c;
    
    for(ll i=0; i < n; i++){
        dist[i][i] = 0;
    }

    while(m--){
        cin >> a >> b >> c;
        if(c < dist[a-1][b-1]){
            dist[a-1][b-1] = c;
            dist[b-1][a-1] = c;
        }
    }
    
    for(ll k = 0; k < n; k++){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                if(dist[k][j] < LLONG_MAX and dist[i][k] < LLONG_MAX){
                    dist[i][j] = min(dist[i][j],dist[k][j] + dist[i][k]);
                }
            }
        }
    }
    
    
    
    while(q--){
        cin >> a >> b;
        
        ll d = dist[a-1][b-1];
        
        if(d != LLONG_MAX){
            cout << d << endl;
        } else{
            cout << -1 << endl;
        }
    }

	return 0;
}
