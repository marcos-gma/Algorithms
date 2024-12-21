#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int height, width;
vector<string> building;
vector<pair<int,int>> vertices;
map<pair<int, int>, pair<int, int>> pred;  

int start_x, start_y, end_x, end_y;

bool possible = false;

bool valid(int x, int y){
    return x >=0 and x < height and y >= 0 and y < width and building[x][y] != '#';
}


void bfs(){

    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));

    building[start_x][start_y] = '#';

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == end_x && y == end_y) {
            possible = true;
            return;  
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny)) {
                building[nx][ny] = '#';
                q.push(make_pair(nx, ny));
                pred[make_pair(nx,ny)] = make_pair(x,y);
            } 
        }
    }

    
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> height >> width;

    building.resize(height);

    char pos;

    for (int i = 0; i < height; i++) {
        cin >> building[i];
        for (int j = 0; j < width; j++){
            if(building[i][j] == 'A'){
                start_x = i;
                start_y = j;
            }
            if(building[i][j] == 'B'){
                end_x = i;
                end_y = j;
            }
        }
    }

    bfs();
    
    if(!possible){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;

        vector<pair<int,int>> path;

        pair<int,int> curr = make_pair(end_x,end_y);

        while(curr != make_pair(start_x, start_y)){
            path.push_back(curr);
            curr = pred[curr];
        }

        path.push_back(make_pair(start_x, start_y));  

        reverse(path.begin(), path.end());

        int size = path.size() - 1;

        cout << size << endl;

        for (int i=0; i < size; i++){
            if(path[i+1].second - path[i].second > 0){
                cout << 'R';
            }
            else if(path[i+1].second - path[i].second < 0){
                cout << 'L';
            }
            else if(path[i+1].first - path[i].first > 0){
                cout << 'D';
            }
            else if(path[i+1].first - path[i].first < 0){
                cout << 'U';
            }
        }

        cout << endl;

    }
    

	return 0;
}
