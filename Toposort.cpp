#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int cour, req, a, b;
    
    cin >> cour >> req;
    
    vector<int> graus(cour+1,0);
    
    vector<int> courses;
    
    vector<vector<int>> adj(cour+1);
    
    while(req--){
        cin >> a >> b;
        graus[b]++;
        adj[a].push_back(b);
    }
    
    queue<int> q;
    
    for(int i=1; i <= cour; i++){
        if(graus[i] == 0){
            q.push(i);
        }
    }
    
    vector<int> toposort;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        toposort.push_back(u);
        
        for(auto v : adj[u]){
            graus[v]--;
            if(graus[v] == 0){
                q.push(v);
            }
        }
    }
    
    if(toposort.size() != cour){
        cout << "IMPOSSIBLE" << endl;
    }
    
    else{
        for(auto x : toposort){
            cout << x << " ";
        }
    }
    
    
	


	return 0;
}
