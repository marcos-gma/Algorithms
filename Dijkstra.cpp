#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;

#define pii pair<ll,ll>
const ll MXN = 1e5+5;
const ll INF = LLONG_MAX;
int V,E;
vector<pii> adj[MXN];
vector<ll> parents(MXN,-1);
vector<ll> distances(MXN,INF);

void dijkstra(ll node){
    distances[node] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,node});
    while(!pq.empty()){
        pii pair = pq.top();
        pq.pop();
        ll d = pair.first, out = pair.second;
        if (d > distances[out]) continue;
        for(auto [cost, n] : adj[out]){
            ll curr = distances[out] + cost;
            if (curr < distances[n]){
                distances[n] = curr;
                parents[n] = out;
                pq.push({curr,n});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cities, connections, a, b, c;

    cin >> cities >> connections;

    while(connections--){
        cin >> a >> b >> c;
        adj[a-1].emplace_back(c,b-1);
    }
    
    dijkstra(0); 

    for(int i = 0; i < cities; i++){
        cout << distances[i] << " ";
    }
    
    return 0;
}
