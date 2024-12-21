#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

vector<bool> visitado;
vector<vector<int>> vizinhos;
vector<int> max_distances;

int max_dist = 0;

int farest;


void dfs(int v, int dist){
    
    visitado[v] = true;
    
    for (auto u : vizinhos[v]){
        if (!visitado[u]){
            if(max_dist < dist + 1){
                farest = u;
                max_dist = dist + 1;
            }
            max_distances[u] = max(max_distances[u],dist+1);
            dfs(u,dist+1);
        }
    }
    
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;

    cin >> n;
    
    int a,b;
    
    visitado.assign(n,false);
    vizinhos.assign(n,{});
    max_distances.assign(n,0);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        vizinhos[a - 1].push_back(b - 1);
        vizinhos[b - 1].push_back(a - 1);
    }
    
    dfs(0,0);
    
    int corner = farest;
    
    farest = 0;
    
    max_dist = 0;
    
    visitado.assign(n,false);
    
    dfs(corner,0);
    
    corner = farest;
    
    farest = 0;
    
    max_dist = 0;
    
    visitado.assign(n,false);
    
    dfs(corner,0);
    
    
    for (auto d : max_distances){
        cout << d << " ";
    }
    
    
    
    
    

	return 0;
}
