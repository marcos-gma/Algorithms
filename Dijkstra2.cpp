#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;

#define pii pair<ll,ll>
const ll MXN = 1e5+5;
const ll INF = LLONG_MAX;
vector<pii> adj[MXN];
vector<ll> distances(MXN,INF);
vector<ll> w(MXN);

void dijkstra(ll node){
    distances[node] = w[0];
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({w[0],node});
    while(!pq.empty()){
        pii pair = pq.top();
        pq.pop();
        ll d = pair.first, out = pair.second;
        if (d > distances[out]) continue;
        for(auto [cost, n] : adj[out]){
            ll curr = distances[out] + cost + w[n];
            if (curr < distances[n]){
                distances[n] = curr;
                pq.push({curr,n});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, a, b, c;

    cin >> n >> m;

    for(ll i = 0; i < n; i++){
        cin >> w[i];
    }

    while(m--){
        cin >> a >> b >> c;
        adj[a-1].emplace_back(c,b-1);
        adj[b-1].emplace_back(c,a-1);
    }
    
    dijkstra(0); 

    for(ll i = 1; i < n; i++){
        cout << distances[i] << " ";
    }
    
    return 0;
}
