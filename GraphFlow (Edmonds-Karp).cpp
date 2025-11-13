#include <bits/stdc++.h>
#include <limits.h>
#define endl "\n"
#define ll long long
#define pll pair<ll,ll>


using namespace std;

vector<vector<ll>> res;

ll mf, f, s, t;

vector<ll> p;

void augment(ll v, ll minEdge){
    if(v == s){
        f = minEdge; return;
    }
    else if (p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n,m;
	
	cin >> n >> m;
	
	vector<ll> x(n,0);
	
	res.resize(n,x);
	
	vector<vector<ll>> adj(n);
	
	for(ll i = 0; i < m; i++){
	    ll a,b,c;
	    cin >> a >> b >> c;
	    a--; b--; 
        if (res[a][b] == 0 && res[b][a] == 0) { 
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        res[a][b] += c;
	}
	
	s = 0;
	t = n - 1;
	
    mf = 0;
    
    while(true){
        f = 0;
        vector<ll> dist(n, LLONG_MAX);
        dist[s] = 0;
        p.assign(n,-1);
        queue<ll> q;
        q.push(s);
        while(!q.empty()){
            ll u = q.front(); q.pop();
            if(u == t) break;
            for(ll v : adj[u]){
                if(res[u][v] > 0 && dist[v] == LLONG_MAX){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }
        augment(t, LLONG_MAX);
        if(f == 0) break;
        mf += f;
    }
    
    cout << mf;
    

	return 0;
}
