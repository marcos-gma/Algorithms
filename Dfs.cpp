#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> cats;
bool visited[100001];
int possibles = 0;
int m;

void dfs(int u, int counter) {
    visited[u] = true;

    if (cats[u] == 1) {
        counter++;
    } else {
        counter = 0;  
    }

    if (counter > m) {
        return; 
    }

    bool possible = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            possible = false;
            dfs(v, counter);
        }
    }

    if (possible) {
        possibles++;  
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a, x, y;
    cin >> n >> m;

    cats.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a;
        cats[i] = a;
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);  
    }

    dfs(1, 0);  

    cout << possibles;

    return 0;
}
