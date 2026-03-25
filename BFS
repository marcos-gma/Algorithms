#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;

#define pii pair<ll,ll>
const ll MXN = 1e5+5;
const ll INF = LLONG_MAX;
vector<vector<ll>> adj;
vector<ll> parents(MXN,-1);
vector<ll> distances(MXN,INF);
int visited;

void bfs(ll node){
    fill(distances.begin(), distances.end(), INF); 
    fill(parents.begin(), parents.end(), -1); 
    
    distances[node] = 0;
    queue<ll> q;
    q.push(node);

    while(!q.empty()){
        ll out = q.front();
        q.pop();
  
        for(auto n : adj[out]){
            if (distances[n] == INF){
                distances[n] = distances[out] + 1; 
                parents[n] = out;
                q.push(n);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, a, b;

    cin >> n >> m;
    
    adj.resize(n);

    while(m--){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    bool p = true;
    
    ll k = 0;
    
    for(ll i=0; i < n; i++){
        bfs(i);
        for(ll j=0; j < n; j++){
            if(distances[j] == INF){
                p = false;
                break;
            } else{
                k = max(k,distances[j]);
            }
        }
        if(not p) break;
    }
    if(not p){
        cout << "=[";
    }
    else{
        cout << "=] " << k;
    }

    return 0;
}
