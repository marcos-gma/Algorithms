#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> cycle;
bool visited[100001];
int m;

int dfs(int u, int prev) {
    
    if(visited[u]) {
        cycle.push_back(u);
        return u;
    }
    
    visited[u] = true;

    for (int v : adj[u]) {
        if (v != prev) {
            int end = dfs(v, u);
            
            if(end != -1){
                cycle.push_back(u);
                return u;
            }
            
            if(end == u or end == -2){
                return -2;
            }

        }
    }
    
    return -1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x, y;
    cin >> n >> m;

    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);  
    };
    
    vector<vector<int>> adj2 = adj;
    
    for(int i=1; i <= n; i++){
        if(!visited[i] and cycle.size() < 3){
            cycle.clear();
            dfs(i, 0);  
        }
    }
    
    vector<int> v = cycle;
    
    if(cycle.size() >= 3){
        int s = cycle.size();
        int start = cycle[0];
        vector<int> ans;
        ans.push_back(cycle[0]);
        int i;
        
        for(i = 1; i < s; i++){
            ans.push_back(cycle[i]);
            if(cycle[i] == start) break;
        }
        
        cout << i + 1 << endl;
        
        for(auto a : ans){
            cout << a << " ";
        }
        
    }else{
        cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}
