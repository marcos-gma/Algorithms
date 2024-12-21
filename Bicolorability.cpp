#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

vector<bool> visitado;
vector<bool> color;
vector<vector<int>> vizinhos;


bool dfs(int v){
    
    visitado[v] = true;
    
    for (auto u : vizinhos[v]){
        if (!visitado[u]){
            color[u] = not color[v];
            if(!dfs(u)){
                return false;
            }
        }
        else if (color[u] == color[v]){
            return false;
        }
    }
    return true;
    
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;

    cin >> n >> m;
    
    int a,b;
    
    visitado.assign(n,false);
    color.assign(n,true);
    vizinhos.assign(n,{});

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vizinhos[a - 1].push_back(b - 1);
        vizinhos[b - 1].push_back(a - 1);
    }
    
    bool possible;
    
    int i = 0;
    
    for(auto v : visitado){
        if(!v){
            possible = dfs(i);
        }
        i++;
    }
    
    if(possible){
        
        for(auto c : color){
            if(c){
                cout << "1 ";
            }else{
                cout << "2 ";
            }
        }
        
    }else{
        cout << "IMPOSSIBLE" << endl;
    }


	return 0;
}
