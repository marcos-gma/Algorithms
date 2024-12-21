#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int height, width;
vector<string> building;
vector<pair<int,int>> vertices;
map<pair<int,int>,int> comp;



bool valid(int x, int y){
    return x >=0 and x < height and y >= 0 and y < width and building[x][y] != '#';
}


void dfs(int x, int y, int cmp_now){
    comp[make_pair(x,y)] = cmp_now;
    building[x][y] = '#';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny)) {
            dfs(nx, ny, cmp_now);
        } 
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> height >> width;

    for (int i = 0; i < height; i++) {
        string s;
        cin >> s;
        building.push_back(s);
    }

    int rooms = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (building[i][j] == '.') {
                rooms++;
                dfs(i, j, rooms);
            }
        }
    }
    
    cout << rooms << endl;


	return 0;
}
